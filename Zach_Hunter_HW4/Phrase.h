#pragma once
#include <string>

class Phrase
{

public:
	// Constructors
	Phrase();
	Phrase(std::string s);

	// Destructors
	~Phrase();

	// Setters
	void setPhrase(std::string phrase);

	// Getters
	std::string original();
	std::string lowercase();
	std::string uppercase();
	std::string reverse(std::string phrase);
	std::string ascending();
	std::string descending();
	std::string sorted(int order);	// Returns ascending if order=0, descending otherwise
	std::string rot13();
	// Bonus feature
	std::string pigLatin();

private:
	std::string originalPhrase;

};

