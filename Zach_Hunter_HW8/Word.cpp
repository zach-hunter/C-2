#include "stdafx.h"
#include "Word.h"


Word::Word()
{
	_word = "";
	_lineList.clear();
}

Word::Word(std::string word)
{
	_word = word;
}


Word::~Word()
{
}

std::string Word::getWord() {
	return _word;
}

bool Word::hasLineNumber(int line) {
	bool foundLineNumber = false;
	for (int lineInList : _lineList) {
		if (line == lineInList) {
			foundLineNumber = true;
		}
	}
	return foundLineNumber;
}

void Word::addLineNumber(int lineNumber) {
	this->_lineList.push_back(lineNumber);
}

int Word::getOccurance() {
	return _lineList.size();
}

std::string Word::toString() {
	std::string temp = "";
	temp = getWord() + "(" + std::to_string(getOccurance()) + "): ";
	for (int i = 0; i < _lineList.size(); i++) {
		temp += std::to_string(_lineList[i]);
		if (i != _lineList.size() - 1) {
			temp += ", ";
		}
	}
	return temp;
}
