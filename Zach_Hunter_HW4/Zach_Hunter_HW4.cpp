// PROG1203_HW4.cpp
// Author: Zach Hunter

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Phrase.h"

using namespace std;

int main()
{
	string newPhrase = "";
	bool done = false;
	Phrase converter = Phrase();

	do {
		cout << "Enter a phrase to work on. (empty to quit) ";
		getline(cin, newPhrase);
		if (newPhrase.empty()) {
			done = true;
			continue;
		}
		converter.setPhrase(newPhrase);

		cout << "Original Phrase   = [" << converter.original() << "]" << endl;
		cout << "Lowercase Phrase  = [" << converter.lowercase() << "]" << endl;
		cout << "Uppercase Phrase  = [" << converter.uppercase() << "]" << endl;
		cout << "Reversed Phrase   = [" << converter.reverse(converter.original()) << "]" << endl;
		cout << "Ascending Phrase  = [" << converter.ascending() << "]" << endl;
		cout << "Descending Phrase = [" << converter.descending() << "]" << endl;
		cout << "Rot13 Phrase      = [" << converter.rot13() << "]" << endl;
		// Uncomment the next line for the bonus feature
		cout << "Pig Latin Phrase  = [" << converter.pigLatin() << "]" << endl;

	} while (!done);

	return 0;
}

