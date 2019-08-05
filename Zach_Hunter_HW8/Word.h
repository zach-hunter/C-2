#pragma once
#include <vector>
#include <string>

class Word
{
public:
	Word();
	Word(std::string word);
	~Word();
	std::string getWord();
	bool hasLineNumber(int line);
	void addLineNumber(int lineNumber);
	int getOccurance();
	std::string toString();
private: 
	std::vector<int> _lineList;
	std::string _word;
};

