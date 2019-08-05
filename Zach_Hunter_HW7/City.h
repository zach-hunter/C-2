#pragma once
#include <string>

class City
{
private:
	std::string _city;
	std::string _country;
	double _long;
	double _lat;
	int _cityIndex;
public:

	City();
	City(std::string city, std::string country, double lat, double longitude, int index);
	
	~City();

	std::string getCity();

	std::string getCountry();

	double getLong();

	double getLat();

	int getCityIndex();

	std::string ToString();

	friend std::ostream& operator<<(std::ostream& stream, City city); //trying my hand at operator overloading, took a while to figure out it needs to be friended and not in std namespace?
};

