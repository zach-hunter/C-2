// PROG1203_HW5.cpp
// Author: Allen W. Baker
// Date: Feb. 10, 2018

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>

#include "LargeInt.h"

using namespace std;

int main()
{
	LargeInt v1, v2, v3, v4;
	string v1Init = "456456456456";
	string v2Init = "456456456456";
	string v3Result = "912912912912";

	// Testing with known results
	v1.setValue(v1Init);
	v2.setValue(v2Init);
	v3 = v1 + v2;

	int fieldWidth = max(v1.size(), max(v2.size(), v3.size()));
	cout << "v1 = " << setw(fieldWidth + 2) << v1.toString() << endl;
	cout << "v2 = " << setw(fieldWidth + 2) << v2.toString() << endl;
	cout << "v3 = " << setw(fieldWidth + 2) << v3.toString() << endl;
	if(v3.toString() == v3Result){
		cout << "Success!" << endl;
	} else {
		cout << "Error in test calculations." << endl;
	}

	// Live testing
	bool done = false;
	do {
		cout << "Enter a value for v1 (0 to exit): " << endl;
		cin >> v1Init;
		if (v1Init == "0") {
			done = true;
			continue;
		}
		while (cin.fail() || !v1.setValue(v1Init)){
			cout << "That wasn't a valid value. Try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> v1Init;
		}

		cout << "Enter a value for v2: " << endl;
		cin >> v2Init;
		while (cin.fail() || !v2.setValue(v2Init)) {
			cout << "That wasn't a valid value. Try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> v2Init;
		}

		// Add the two input values, placing the result in the third variable
		v3 = v1 + v2;

		int fieldWidth = max( max(v1.size(), v2.size()), max(v3.size(), v4.size()));
		cout << "v1 = " << setw(fieldWidth + 2) << v1.toString() << endl;
		cout << "v2 = " << setw(fieldWidth + 2) << v2.toString() << endl;
		cout << "v3 = " << setw(fieldWidth + 2) << v3.toString() << endl;
		// Uncomment the following statements to test Bonus features
		v4 = v1 - v2;
		cout << "v4 = " << setw(fieldWidth + 2) << v4.toString() << endl;

	} while (!done);




	system("pause");
    return 0;
}

