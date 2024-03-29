// Zach_Hunter_HW8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Concordance.h"


using namespace std;

void parseWordsOf(string fileName);
Concordance wordList;

int main()
{
	bool isUserDone = false;
	while (!isUserDone) {
		wordList.clear();
		cout << "Select file to create concordance(0 to exit): " << endl <<
			"1. Apology.txt" << endl <<
			"2. MobyDick.txt" << endl <<
			"3. ModestProposal.txt" << endl <<
			"4. ShortHistory.txt" << endl <<
			"5. WizardOfOz.txt" << endl << endl;
		int choice = 0;
		cin >> choice;
		while (cin.fail() || choice < 0 || choice > 5) {
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Invalid entry, try again" << endl;
			cin >> choice;
		}
		string fileName = "";
		switch (choice) {
		case 1:
			fileName = "Apology";
			break;
		case 2:
			fileName = "MobyDick";
			break;
		case 3:
			fileName = "ModestProposal";
			break;
		case 4:
			fileName = "ShortHistory";
			break;
		case 5:
			fileName = "WizardOfOz";
			break;
		case 0:
			isUserDone = true;
			continue;
		default:
			continue;
		}
		parseWordsOf(fileName + ".txt");
		wordList.saveToFile(fileName);

	}
    return 0;
}

void parseWordsOf(string fileName) {
	const char SPACE_CHARACTER = ' ';
	ifstream file;
	file.open(fileName);
	while (!file.is_open()) {
		cout << "FILE NOT FOUND - "<< fileName << endl;
		cin.get();
	}
	int pos1 = 0;
	string line = "";
	string tempWord = "";
	string space = " ";
	int lineCount = 0;
	while (!file.eof()) {
		getline(file, line);
		lineCount++;
		pos1 = 0;
		if (line == "" || line == " ") {
			continue;
		}
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == SPACE_CHARACTER || i == line.length()-1) { //uses space as delimiter for words
				if (i == line.length() - 1) {
					tempWord = line.substr(pos1, i+1 - pos1);
				}
				else {
					tempWord = line.substr(pos1, i - pos1);
				}
				pos1 = i + 1;
				int stringLength = tempWord.length();
				if (tempWord == "") {
					continue;
				}
				while (ispunct(tempWord[0])) {  //gets rid of leading punctuation
					stringLength--;
					if (stringLength == 0) {
						break;
					}
					tempWord = tempWord.substr(1, stringLength);
				}
				if (stringLength > 0) {  //gets rid of trailing punctuation
					while (ispunct(tempWord.at(stringLength - 1))) {
						stringLength--;
						if (stringLength == 0) {
							break;
						}
						tempWord = tempWord.substr(0, stringLength);
					}
				}
				string completeWord = "";
				for (char character : tempWord) {
					completeWord += tolower(character);
				}
				if (completeWord == "" || completeWord == " " || (completeWord.length() == 1 && ispunct(completeWord[0]))) {
					continue;
				}
				if (!wordList.containsWord(completeWord)) {
					wordList.addWord(completeWord, lineCount);
				}
				else {
					wordList.addLine(completeWord, lineCount);
				}

			}
		}
		
	}
	file.close();
}

