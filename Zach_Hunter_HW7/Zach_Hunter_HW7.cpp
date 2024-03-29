// Zach_Hunter_HW7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "City.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

vector<City> cityList;
vector<double> distanceList;
void distanceCalc(City &city);
double degreeToRadian(double degree);
void readCSV(string fileName);
void sortByDistance();
void printClosest(int num);
void printFarthest(int num);

int main()
{
	bool userDone = false;
	string input;
	int integerInput = 0;
	City selectedCity;
	while (!userDone) {
		cityList.clear();
		readCSV("worldcities.csv");
		distanceList.clear();
		cout << "Enter a city name or index(Enter \"Quit\" to exit): ";
		getline(cin, input);
		if (input == "Quit") {
			userDone = true;
			continue;
		}
		bool onlyNumbers = true;
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
				onlyNumbers = false;
			}
		}
		if (onlyNumbers) {
			integerInput = stoi(input);
			if (integerInput < 1 || integerInput > cityList.size()) {
				cout << "Invalid city index. Range is 1 to " << to_string(cityList.size()) << "." << endl;
				continue;
			} else {
				selectedCity = cityList[integerInput - 1];
				distanceCalc(selectedCity);
			}
		}
		else {
			string lowerInput = "";
			bool cityFound = false;
			for (char character : input) {
				lowerInput += tolower(character);
			}
			for (City city : cityList) {
				string lowerCityName = "";
				for (char character : city.getCity()) {
					lowerCityName += tolower(character);
				}
				if (lowerInput == lowerCityName) {
					selectedCity = city;
					cityFound = true;
				}
			}
			if (!cityFound) {
				cout << "City name not found, try again. " << endl;
				continue;
			}
			else {
				distanceCalc(selectedCity);
			}
		}
		sortByDistance();
		cout << endl;
		cout << "5 closest to " << selectedCity << ":" << endl;
		printClosest(5);
		cout << endl;
		cout << "5 farthest from " << selectedCity << ":" << endl;
		printFarthest(5);
		cout << endl;
	}
    return 0;
}

void readCSV(string filename) {
	ifstream file;
	file.open(filename);
	while (!file.is_open()) {
		cout << "FILE NOT FOUND - worldcities.csv" << endl;
		cin.get();
	}
	int pos1, pos2 = 0;
	string city = "";
	string country = "";
	double lat = 0.0;
	double longitude = 0.0;
	string inLine = "";
	int cityIndex = 0;
	getline(file, inLine);
	while (!file.eof()) {
		getline(file, inLine);
		if (inLine == "") {
			break;
		}
		pos1 = 0;
		pos2 = inLine.find(',', pos1);
		city = inLine.substr(pos1, pos2 - pos1);
		pos1 = pos2 + 1;
		pos2 = inLine.find(',', pos1);
		country = inLine.substr(pos1, pos2 - pos1);
		pos1 = pos2 + 1;
		pos2 = inLine.find(',', pos1);
		lat = stod(inLine.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		longitude = stod(inLine.substr(pos1));
		cityIndex += 1;
		City city(city, country, lat, longitude, cityIndex);
		cityList.push_back(city);
	}
}

void sortByDistance() {
	City tempCity;
	double tempDistance;
	for (int h = 0; h < cityList.size(); h++) {
		for (int i = 0; i < cityList.size() - 1; i++) {
			if (distanceList[i] > distanceList[i + 1]) {
				tempCity = cityList[i];
				tempDistance = distanceList[i];
				cityList[i] = cityList[i + 1];
				distanceList[i] = distanceList[i + 1];
				cityList[i + 1] = tempCity;
				distanceList[i + 1] = tempDistance;
			}
		}
	}
}

void printClosest(int howMany) {
	for (int i = 1; i < howMany + 1; i++) {
		cout << cityList[i] << ": " << distanceList[i] << "km" << endl;
	}
}

void printFarthest(int howMany) {
	for (int i = cityList.size(); cityList.size() - i < howMany; i--) {
		cout << cityList[i-1] << ": " << distanceList[i-1] << "km" << endl;
	}
}
double degreeToRadian(double number) {  //converts to radians for distance formula
	const double pi = 4 * atan(1);
	return pi * number / 180.00;
}

void distanceCalc(City &city) //trying out passing by reference to avoid unnecessary copying
{
	double lat1 = degreeToRadian(city.getLat());
	double lat2 = 0.0;
	double long1 = degreeToRadian(city.getLong());
	double long2 = 0.0;
	double const earthRadius = 6372.8;

	for (City cityInList : cityList) {
		lat2 = degreeToRadian(cityInList.getLat());
		long2 = degreeToRadian(cityInList.getLong());
		
		double changeInLat = lat2 - lat1;
		double changeInLong = long2 - long1;

		double distance = asin(sqrt(sin(changeInLat / 2) * sin(changeInLat / 2) + cos(lat1) * cos(lat2) * sin(changeInLong / 2) * sin(changeInLong / 2)));  //haversine distance formula
		distance = distance * 2 * earthRadius;
		distanceList.push_back(distance);
	}
}
