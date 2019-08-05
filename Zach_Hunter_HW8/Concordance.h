#pragma once
#include <vector>
#include "Word.h"
#include <string>
#include <fstream>
#include <iostream>

class Concordance
{
public:
	Concordance();
	~Concordance();
	bool containsWord(std::string word);
	void addWord(std::string word, int line);
	void addLine(std::string word, int line);
	void sortByWord();
	void sortByOccurance();
	void saveToFile(std::string fileName);
	void clear();
private:
	std::vector<Word> _wordList;
};

