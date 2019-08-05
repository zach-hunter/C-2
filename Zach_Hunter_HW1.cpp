// Zach_Hunter_HW1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <cmath>
#include <string>


using namespace std;

int main()
{
while(true) {
	double triside1 = 0;
	double triside2 = 0;
	double triside3 = 0;

	cout << "Input lengths of each triangle side in inches(0 to exit)" << endl;
	cout << "Side 1: ";
	cin >> triside1;
	if (triside1 == 0) {
		break;
	}
	while (triside1 < 0.1 || cin.fail()) { //validation checking
		cin.clear();
		cin.ignore(1000000, '\n'); //clearing input buffer if cin failed
		cout << "Invalid length. Length for each side must be greater than 0.1 inches." << endl << "Side 1: ";
		cin >> triside1;
	}
	cout << "Side 2: ";
	cin >> triside2;
	if (triside2 == 0) {
		break;
	}
	while (triside2 < 0.1 || cin.fail()) { //validation checking
		cin.clear();
		cin.ignore(1000000, '\n'); //clearing input buffer if cin failed
		cout << "Invalid length. Length for each side must be greater than 0.1 inches." << endl << "Side 2: ";
		cin >> triside2;
	}
	cout << "Side 3: ";
	cin >> triside3;
	if (triside3 == 0) {
		break;
	}
	while (triside3 < 0.1 || cin.fail()) { //validation checking
		cin.clear();
		cin.ignore(1000000, '\n'); //clearing input buffer if cin failed
		cout << "Invalid length. Length for each side must be greater than 0.1 inches." << endl << "Side 3: ";
		cin >> triside3;
	}
	double newside1 = 0;
	double hypot = 0;
	double newside2 = 0;
	string triangletype = "Scalene triangle"; //default to scalene because it will be the last remaining choice
	string hypotname = "";
	if (triside1 == triside2 && triside1 == triside3) {  //determines if triangle is equilateral
		hypot = triside1;
		hypotname = "None. All sides equal in length.";
		newside1 = triside2;
		newside2 = triside3;
		triangletype = "Equilateral triangle";
	}
	if ((triside1 == triside2 && triside1 != triside3) || (triside1 == triside3 && triside1 != triside2) || (triside2 == triside3 && triside2 != triside1)) {  //determines if triangle is isosceles
		hypot = triside1;
		hypotname = "None. Two sides are equal in length.";
		newside1 = triside2;
		newside2 = triside3;
		triangletype = "Isosceles triangle";
	}
	if (triside1 > triside2 && triside1 > triside3) {  //reorganizing sides by length
		hypot = triside1;
		hypotname = "Side 1";
		newside1 = triside2;
		newside2 = triside3;
	}
	if (triside2 > triside1 && triside2 > triside3) {
		hypot = triside2;
		hypotname = "Side 2";
		newside1 = triside1;
		newside2 = triside3;
	}
	if (triside3 > triside1 && triside3 > triside2) {
		hypot = triside3;
		hypotname = "Side 3";
		newside1 = triside1;
		newside2 = triside2;
	}
	double hypotcalc = 0;
	string isitright = "";
	hypotcalc = sqrt(newside1*newside1 + newside2 * newside2);  //pythag theorem
	if (hypotcalc == hypot) {  //determines if right triangle or not
		triangletype = "Right triangle";
		isitright = "Is a right triangle";
	}
	else {
		isitright = "Not a right triangle";
	}
	cout << "Triangle information:" << endl << "Side 1: " << triside1 << " inches" << endl; //outputs results
	cout << "Side 2: " << triside2 << " inches" << endl;
	cout << "Side 3: " << triside3 << " inches" << endl;
	cout << "Apparent hypotenuse length: " << hypot << " inches" << endl;
	cout << "Calculated hypotenuse length: " << hypotcalc << " inches" << endl;
	cout << "Result: " << isitright << endl;
	cout << "Triangle type(Bonus): " << triangletype << endl;
}

	system("pause");
    return 0;
}



