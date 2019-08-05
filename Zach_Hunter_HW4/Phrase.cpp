#include "stdafx.h"
#include "Phrase.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>


// Constructors
Phrase::Phrase()
{
	originalPhrase = "";
}

Phrase::Phrase(std::string s)
{
	originalPhrase = s;
}


// Destructors
Phrase::~Phrase()
{
}

// Setters
void Phrase::setPhrase(std::string s) {
	originalPhrase = s;
}

// Getters
std::string Phrase::original() {
	return originalPhrase;
}
std::string Phrase::lowercase() {
	std::string temp = Phrase::original();
	std::string lower = "";
	for (int i = 0; i < temp.length(); i++) {
		lower += tolower(temp[i]);
	}
	return lower;
}
std::string Phrase::uppercase() {
	std::string temp = Phrase::original();
	std::string upper = "";
	for (int i = 0; i < temp.length(); i++) {
		upper += toupper(temp[i]);
	}
	return upper;
}

std::string Phrase::reverse(std::string phrase) {
	std::string reversed = "";
	int lastSpace = phrase.length() - 1;
	for (int i = lastSpace; i >= 0; i--) {  //starts at end of string, appends new words going backwards to beginning of new string which reverses order
		if (phrase.at(i) == ' ' && i != 0) {
			reversed.append(phrase.substr(i, lastSpace - i + 1));
			lastSpace = i - 1;
		}
		if (i == 0) { //appends first word to end of string
			reversed.append(" ");
			reversed.append(phrase.substr(i, lastSpace + 1));

		}
	}
	return reversed;
}
std::string Phrase::ascending() {
	return Phrase::sorted(0);
}
std::string Phrase::descending() {
	return Phrase::sorted(1);
}
std::string Phrase::sorted(int order) {	// Returns ascending if order=0, descending otherwise
	std::string phrase = Phrase::original();
	std::string sorted = "";
	double phraseLength = phrase.length();
	int lastSpace = 0;
	int numWords = 1;
	int wordCount = 0;
	for (int i = 0; i < phraseLength; i++) { //counts amount of words in phrase
		if (phrase.at(i) == ' ') {
			numWords++;
		}
	}
	std::string *stringArray = nullptr;
	stringArray = new std::string[numWords];
	for (int i = 0; i < phraseLength; i++) {
		if (phrase.at(i) == ' ') {
			stringArray[wordCount] = phrase.substr(lastSpace, i - lastSpace); //adds new word to string if it hits a space
			lastSpace = i + 1;
			wordCount++;
		}
		if (i + 1 == phraseLength) {
			stringArray[wordCount] = phrase.substr(lastSpace, i - lastSpace + 1); //adds last word to string since no space will be found
			lastSpace = i + 1;
		}
	}
	for (int i = 0; i < numWords - 1; i++) {  //sorts array
		for (int j = i + 1; j < numWords; j++) {
			std::string temp;
			if (stringArray[i] > stringArray[j]) {
				temp = stringArray[i];
				stringArray[i] = stringArray[j];
				stringArray[j] = temp;
			}
		}
	}
	for (int i = 0; i < numWords; i++) { //builds new string based on order in array
		sorted = sorted.append(stringArray[i].append(" "));
	}
	while (sorted[0] == ' ') {  //gets rid of spaces at the beginning of string
		sorted = sorted.substr(1, sorted.length() - 1);
	}
	delete[] stringArray; //array cleanup
	if (order == 0) {
		return sorted;
	}
	else {
		return reverse(sorted);
	}
}
std::string Phrase::rot13() {
	std::string phrase = Phrase::original();
	std::string rot13ed = "";
	const int ROT_13 = 13; //rot13 shifts each letter 13 places
	const int A = 65;  //corresponding ascii values for A-Z and a-z range
	const int Z = 90;
	const int a = 97;
	const int z = 122;
	int temp = 0;
	char tempChar = ' ';
	for (int i = 0; i < phrase.length(); i++) {
		tempChar = phrase[i];
		temp = (int)tempChar;  //casts the character at i into an int
		if (temp >= A && temp <= Z) { //A-Z ascii numbers
			temp += ROT_13;
			if (temp > Z) { //wraps back around to keep within range
				temp = A - 1 + (temp - Z);
			}
		}
		if (temp >= a && temp <= z) { //a-z ascii numbers
			temp += ROT_13;
			if (temp > z) { //wraps back around to keep within range
				temp = a - 1 + (temp - z);
			}
		}
		tempChar = (char)temp;
		rot13ed += tempChar;

	}
	return rot13ed;
}

std::string Phrase::pigLatin() {
	std::string phrase = Phrase::original();
	std::string piged = "";
	int phraseLength = phrase.length();
	int numWords = 1;
	int wordCount = 0;
	int lastSpace = 0;
	for (int i = 0; i < phraseLength; i++) { //counts amount of words in phrase
		if (phrase.at(i) == ' ') {
			numWords++;
		}
	}
	std::string *stringArray = nullptr;
	stringArray = new std::string[numWords];
	for (int i = 0; i < phraseLength; i++) {
		if (phrase.at(i) == ' ') {
			stringArray[wordCount] = phrase.substr(lastSpace, i - lastSpace); //adds new word to array if it hits a space
			lastSpace = i + 1;
			wordCount++;
		}
		if (i + 1 == phraseLength) {
			stringArray[wordCount] = phrase.substr(lastSpace, i - lastSpace + 1); //adds last word to array since no space will be found
			lastSpace = i + 1;
		}
	}
	for (int i = 0; i < numWords; i++) { //loop to go through each word in the string array and convert to pig latin
		bool wordHasVowel = false;
		int tempSize = stringArray[i].length();
		if (stringArray[i] == "a") {
			piged = piged + "ay ";
		}
		else {
			for (int j = 0; j < tempSize; j++) {

				if (stringArray[i][j] == 'a' || stringArray[i][j] == 'e' || stringArray[i][j] == 'i' || stringArray[i][j] == 'o' || stringArray[i][j] == 'u') {
					piged = piged + stringArray[i].substr(j, tempSize - j) + stringArray[i].substr(0, j) + "ay ";
					wordHasVowel = true;
					break;
				}
			}

			if (!wordHasVowel) {
				piged = piged + stringArray[i] + " ";
			}
		}
	}

	return piged;

}

