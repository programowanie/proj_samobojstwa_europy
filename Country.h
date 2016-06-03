#pragma once
#include <vector>
#include <string>

using namespace std;

class Country {
	private: 
		//statistics taken mostly from wikipedia and similiar sources
		string _name; //name of the country
		unsigned int _population; //real population number
		float _tourism; //the bigger, the better
		int _healthcare; //the smaller, the better
		vector <Country *> borders; //list of countries which borders with this country

		bool _stateOfBorders; //if borders are closed, pathogen cant get into the country

		static vector<Country *> init_countries();

	public:
		unsigned int sick; //number of sick people
		unsigned int dead; //number of dead people
		static unsigned int total_sick; //total number of sick people
		static unsigned int total_dead; //total number of dead people
		static unsigned int total_population; //total population
		static unsigned int total_spread; //total number of countries affected by pathogen

		static vector<Country *> init();
		Country(string name, int population, float tourism, int healthcare);

		string get_name();
		int get_population();
		float get_tourism();
		int get_healthcare();
		vector<Country *> get_borders();
		bool get_state_of_borders();
		void push_borders(Country *country);
};