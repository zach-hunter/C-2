// Zach_Hunter_HW2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string noVowels(string userString);
string noCons(string userString);
string noDigits(string userString);
string noPunct(string userString);
string noCustom(string userString, string customSet);


int main()
{
	bool userDone = false;
	string userString;
	while (!userDone) {
		cout << "Enter a string(0 to exit): ";
		getline(cin, userString);
		if (userString == "0") {
			userDone = true;
			return 0;
		}
		int userChoice = -1;
		while (userChoice != 0) {
			cout << "Choose which character set to eliminate(0 for new string):" << endl <<
				"1. Vowels" << endl <<
				"2. Consonants" << endl <<
				"3. Digits" << endl <<
				"4. Punctuation" << endl <<
				"5. Custom character set" << endl;
			cin >> userChoice;
			while (cin.fail() || userChoice < 0 || userChoice > 5) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid choice, try again." << endl;
				cin >> userChoice;
			}
			cin.ignore();
			string changedString;
			string customSet;
			switch (userChoice) {
			case 0:
				continue;
				break;
			case 1:
				changedString = noVowels(userString);
				break;
			case 2:
				changedString = noCons(userString);
				break;
			case 3:
				changedString = noDigits(userString);
				break;
			case 4:
				changedString = noPunct(userString);
			case 5:
				cout << "Enter character set you wish to delete: ";
				getline(cin, customSet);
				changedString = noCustom(userString, customSet);
				break;
			default:
				//doNothing();
				break;

			}
			cout << endl << "Entered string: " << userString << endl;
			cout << setw(16) << "New string: " << changedString << endl << endl;
		}
	}
    return 0;
}

string noVowels(string userString)
{
	string modifiedString;
	int userLength = userString.length();
	for (int i = 0; i < userLength; i++) {
		if (userString[i] == 'a' || userString[i] == 'e' || userString[i] == 'i' || userString[i] == 'o' || userString[i] == 'u' || userString[i] == 'A' || userString[i] == 'E' || userString[i] == 'I' || userString[i] == 'O' || userString[i] == 'U') {
			//doNothing(); removes character
		}
		else {
			modifiedString += userString[i];
		}
	}
	return modifiedString;
}

string noCons(string userString)
{
	string modifiedString;
	int userLength = userString.length();
	for (int i = 0; i < userLength; i++) {
		if (userString[i] != 'a' && userString[i] != 'e' && userString[i] != 'i' && userString[i] != 'o' && userString[i] != 'u' && userString[i] != 'A' && userString[i] != 'E' && userString[i] != 'I' && userString[i] != 'O' && userString[i] != 'U' && !isdigit(userString[i]) && !ispunct(userString[i]) && userString[i] != ' ') {
			//doNothing(); removes character
		}
		else {
			modifiedString += userString[i];
		}
	}
	return modifiedString;
}

string noPunct(string userString)
{
	string modifiedString;
	int userLength = userString.length();
	for (int i = 0; i < userLength; i++) {
		if (!ispunct(userString[i])) {
			modifiedString += userString[i];
		}
		//else doNothing(); removes character
	}
	return modifiedString;
}

string noCustom(string userString, string customSet)
{
	string modifiedString = "";
	int userLength = userString.length();
	int customLength = customSet.length();
	bool hasMatch = false;
	for (int i = 0; i < userLength; i++) {
		hasMatch = false;
		for (int j = 0; j < customLength; j++) {
			if (userString[i] == customSet[j]){
				hasMatch = true;
			} //else doNothing();
		}
		if (!hasMatch) {
			modifiedString += userString[i];
		} //else doNothing(); removes character
	}
	return modifiedString;
}

string noDigits(string userString)
{
	string modifiedString;
	int userLength = userString.length();
	for (int i = 0; i < userLength; i++) {
		if (!isdigit(userString[i])) {
			modifiedString += userString[i];
		}
		//else doNothing(); removes character
	}
	return modifiedString;
}
