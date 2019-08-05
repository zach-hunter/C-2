// Zach_Hunter_HW3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Number.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


int main()
{
	while (true) {
		cout << "Enter integer(0 to exit): ";
		long long int userNumber;
		cin >> userNumber;
		while (cin.fail()) {  //validation check
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Invalid entry. Enter integer(0 to exit): ";
			cin >> userNumber;
		}
		if (userNumber == 0) {
			break;
		}
		while (userNumber % 10 == 0) {  //checks for trailing 0s and gets rid of them
			userNumber = userNumber / 10;
		}
		Number firstNum;
		firstNum.setNumber(userNumber);
		cout << setw(13) << left << "You entered: " << userNumber << endl;
		cout << setw(13) << left << "Reversed: " << firstNum.reverse() << endl;
		cout << setw(userNumber < 0 ? 14 : 13) << left << "Sorted: " << firstNum.sortNum() << endl << endl;
		

	}
    return 0;
}

