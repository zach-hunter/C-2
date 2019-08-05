#include "stdafx.h"
#include "City.h"
#include <string>


City::City()
{
	this->_city = " ";
	this->_country = " ";
	this->_lat = 0.0;
	this->_long = 0.0;
	this->_cityIndex = 0;
}

City::City(std::string city, std::string country, double lat, double longitude, int index)
{
	this->_city = city;
	this->_country = country;
	this->_lat = lat;
	this->_long = longitude;
	this->_cityIndex = index;
}


City::~City()
{
}

std::ostream & operator<<(std::ostream& stream, City city) {
	 return stream << city.ToString();
}

std::string City::getCity() {
	return this->_city;
}

std::string City::getCountry() {
	return this->_country;
}

double City::getLong() {
	return this->_long;
}

double City::getLat() {
	return this->_lat;
}

int City::getCityIndex() {
	return this->_cityIndex;
}

std::string City::ToString() {
	std::string temp;
	std::string latString =
		temp = getCity() + ", " + getCountry();
	return temp;
}

