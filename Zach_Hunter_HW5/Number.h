#include <string>
#pragma once
class Number
{
private: 
	int _number;
public:
	Number();
	~Number();

	void setNumber(int newNumber);

	int getNumber();

	int reverse();
	int sortNum();
};

