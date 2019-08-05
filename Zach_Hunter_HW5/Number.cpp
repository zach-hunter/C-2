#include "stdafx.h"
#include "Number.h"
#include <string>


Number::Number()
{
	_number = 0;
}


Number::~Number()
{
}

void Number::setNumber(int number) {
	_number = number;
}

int Number::getNumber() {
	return _number;
}

int Number::reverse() {  //reverses number
	int number = getNumber();
	int reverse = 0;
	while (number != 0) {
		reverse = reverse * 10;
		reverse = reverse + (number % 10);
		number = number / 10;
	}
	return reverse;
}

int Number::sortNum() {  //number sort bonus
	int number = getNumber();
	if (number < 0) {
		number = number * -1; //make number positive
	}
	std::string numString = std::to_string(number);  //convert to string
	for (int i = 0; i <= numString.length() - 2; i++) { //bubble sort
		for (int j = i + 1; j <= numString.length()-1; j++) {
			int temp;
			if (numString[i] > numString[j]) {
				temp = numString[i];
				numString[i] = numString[j];
				numString[j] = temp;
			}
		}
	}
	number = stoi(numString); //convert back to int
	return number;


}