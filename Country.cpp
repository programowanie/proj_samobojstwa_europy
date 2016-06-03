#include "Country.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

unsigned int Country::total_sick = 1;
unsigned int Country::total_dead = 0;
unsigned int Country::total_population = 0;
unsigned int Country::total_spread = 1;

Country::Country(string name, int population, float tourism, int healthcare):
	_name(name),
	_population(population),
	_tourism(tourism),
	_healthcare(healthcare)
{
	sick = 0;
	dead = 0;
	_stateOfBorders = true;
}

vector<Country *> Country::init() {
	static vector<Country *> countries = (cout << "Inicjalizacja państw... ", Country::init_countries());
	return countries;
}

vector<Country *> Country::init_countries() {
	vector<Country *> countries;
	ifstream countries_file("countries.dat"); //getting list of countries and its properties
	string line;
	while (getline(countries_file, line)) {
		istringstream stream(line);
		string element[4];
		for (int i = 0; i < 4 && getline(stream, element[i], ','); i++) {
		}
		Country *country = new Country(((element[0][0] = toupper(element[0][0])), element[0]), stoi(element[1]), stof(element[2]), stoi(element[3]));
		total_population += stoi(element[1]);
		countries.push_back(country);
	}
	countries_file.close();

	ifstream borders_file("borders.dat"); //inicializing borders of countries
	while (getline(borders_file, line)) {
		istringstream stream(line);
		string element[2];
		for (int i = 0; i < 2 && getline(stream, element[i], ','); i++) {
		}
		Country *first_country, *second_country;
		for (int j = 0; j < (signed int)countries.size(); j++) {
			if (countries[j]->get_name() == (element[0][0] = toupper(element[0][0]), element[0])) first_country = countries[j];
			if (countries[j]->get_name() == (element[1][0] = toupper(element[1][0]), element[1])) second_country = countries[j];
		}
		first_country->push_borders(second_country);
		second_country->push_borders(first_country);
	}
	cout << "zakończone!";
	return countries;
}

string Country::get_name() {
	return _name;
}

int Country::get_population() {
	return _population;
}

float Country::get_tourism() {
	return _tourism;
}

int Country::get_healthcare() {
	return _healthcare;
}

bool Country::get_state_of_borders() {
	return _stateOfBorders;
}

vector <Country *> Country::get_borders() {
	return borders;
}

void Country::push_borders(Country *country) {
	borders.push_back(country);
}