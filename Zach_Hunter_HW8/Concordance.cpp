#include "stdafx.h"
#include "Concordance.h"


Concordance::Concordance()
{
	_wordList.clear();
}


Concordance::~Concordance()
{
}

bool Concordance::containsWord(std::string word) {
	bool foundWord = false;
	for (Word wordInList : _wordList) {
		if (word == wordInList.getWord()) {
			foundWord = true;
		}
	}
	return foundWord;
}

void Concordance::addWord(std::string word, int line) {
	Word tempWord(word);
	tempWord.addLineNumber(line);
	_wordList.push_back(tempWord);
}

void Concordance::addLine(std::string word, int line) {
	for (int i = 0; i < _wordList.size(); i++) {
		if (_wordList[i].getWord() == word) {
			_wordList[i].addLineNumber(line);
		}
	}
}

void Concordance::sortByWord() {
	Word *tempWord = new Word();
	for (int h = 0; h < _wordList.size(); h++) {
		for (int i = 0; i < _wordList.size() - 1; i++) {
			if (_wordList[i].getWord() > _wordList[i + 1].getWord()) {
				*tempWord = _wordList[i];
				_wordList[i] = _wordList[i + 1];
				_wordList[i + 1] = *tempWord;
			}
		}
	}
	delete tempWord;
}

void Concordance::sortByOccurance() {
	Word *tempWord = new Word();
	for (int h = 0; h < _wordList.size(); h++) {
		for (int i = 0; i < _wordList.size() - 1; i++) {
			if (_wordList[i].getOccurance() < _wordList[i + 1].getOccurance()) {
				*tempWord = _wordList[i];
				_wordList[i] = _wordList[i + 1];
				_wordList[i + 1] = *tempWord;
			}
		}
	}
	delete tempWord;
}

void Concordance::saveToFile(std::string fileName) {
	std::string occuranceFileName = fileName + "_popular.txt";
	std::string alphabeticalFileName = fileName + "_concordance.txt";
	std::ofstream output;
	output.open(alphabeticalFileName);
	sortByWord();
	for (Word &word : _wordList) {
		output << word.toString() << std::endl;
	}
	output.close();
	output.open(occuranceFileName);
	sortByOccurance();
	for (Word &word : _wordList) {
		output << word.toString() << std::endl;
	}
	output.close();
	std::cout << "Alphabetical concordance saved to " << alphabeticalFileName << std::endl <<
		"Occurance concordance saved to " << occuranceFileName << std::endl << std::endl;
}

void Concordance::clear() {
	_wordList.clear();
}
