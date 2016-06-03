#include "Pathogen.h"
#include <math.h>
#include <stdlib.h>

Pathogen::Pathogen(int contagiousness, int resistance, int progressionSpeed): 
			_contagiousness(contagiousness),
			_resistance(resistance),
			_progressionSpeed(progressionSpeed)
{
}

int Pathogen::get_contagiousness() {
	return _contagiousness;
}

void Pathogen::spread_locally(vector <Country *> countries) {
	for (int i = 0; i < (signed int)countries.size(); i++) {
		if ((countries[i]->sick + countries[i]->dead) < (unsigned)countries[i]->get_population()) {
			float factor = 0.5;
			float contagiousness = 0.25 + (float)_contagiousness/200; //contagiousness factor
			float population_factor = ((float)(countries[i]->get_population() - countries[i]->sick - countries[i]->dead))/countries[i]->get_population(); //more sick people -> lower chance to infect helthy person
			if (population_factor <= 0) population_factor = 0; //justincase
			else if (population_factor < 0.01) population_factor = 0.01; //so we don't need to wait forever for the last person in the countryto get sick
			float healthcare_factor = (50 + 50*(float)countries[i]->get_healthcare()/150)/100; //better healthcare country has -> lower chance to infect another person
			float resistance_factor = healthcare_factor + (1-healthcare_factor)*(_resistance/10); //more resistant patoghen -> healthcare is less significant
			float chance = factor*contagiousness*population_factor*resistance_factor;
			int infected = 0;
			if (countries[i]->sick < 100) { //if number of sick people is < 100, we can use "real" randomness
				for (int j = 0; j < (signed int)countries[i]->sick; j++) {
					if (rand()%1000001 < chance*1000000) infected++;
				}
			}
			else infected = countries[i]->sick*chance*((float)(100+(rand()%2-1))/100); //if number is bigger than 100, it's better to use approximation
			if (infected > (countries[i]->get_population() - (signed)countries[i]->sick - (signed)countries[i]->dead)) infected = countries[i]->get_population() - countries[i]->sick - countries[i]->dead;
			countries[i]->sick += infected;
			Country::total_sick += infected;
		}
	}
}

void Pathogen::spread_globally(vector <Country *> countries) {
	for (int i = 0; i < (signed int)countries.size(); i++) {
		if (countries[i]->get_state_of_borders() == true && countries[i]->sick > 0) { //if the borders are closed, pathogen cant get out of the country
			vector <pair<Country *, float>> countries_and_tourism;
			float total_tourism = 0;
			for (int j = 0; j < (signed int)countries.size(); j++) {
				if (countries[j]->get_state_of_borders()) {
					total_tourism += countries[j]->get_tourism();
					for (int k = 0; k < (signed)countries[i]->get_borders().size(); k++) {
						if (countries[j] == countries[i]->get_borders()[k]) total_tourism += 10; //if countries border, the chance of spreading the pathogen is much bigger
					}
				}
				countries_and_tourism.push_back(make_pair(countries[j], total_tourism));
			}

			float random = ((float)(rand()%((int)(total_tourism*100 + 1)) - 10))/100;
			Country * country_picked;
			for (int j = 0; j < (signed)countries_and_tourism.size(); j++) {
				if (countries_and_tourism[j].second > random) {
					country_picked = countries_and_tourism[j].first;
					break;
				}
			}

			if (country_picked != countries[i] && country_picked->sick == 0) {
				float factor = 0.0001;
				float contagiousness = 0.25 + (float)_contagiousness/200; //contagiousness factor
				float chance = factor*contagiousness;
				int infected = 0;
				if (countries[i]->sick < 100) { //if number of sick people is < 100, we can use "real" randomness
					for (int j = 0; j < (signed int)countries[i]->sick; j++) {
						if (rand()%1000001 < chance*1000000) infected++;
					}
				}
				else infected = countries[i]->sick*chance*((float)(100+(rand()%2-1))/100); //if number is bigger than 100, it's better to use approximation
				country_picked->sick += infected;
				if (infected > 0) Country::total_spread += 1;
				Country::total_sick += infected;
			}
		}
	}
}

void Pathogen::kill(vector <Country *> countries) {
	for (int i = 0; i < (signed)countries.size(); i++) {
		float factor = 0.7;
		float progression = ((float)_progressionSpeed)/100; //progression factor
		float chance = factor*progression;
		int dead = 0;
		if (countries[i]->sick < 100) { //if number of sick people, we can use "real" randomness
			for (int j = 0; j < (signed int)countries[i]->sick; j++) {
				if (rand()%1000001 < chance*1000000) dead++;
			}
		}
		else dead = countries[i]->sick*chance*((float)(100+(rand()%2-1))/100); //if number is bigger than 100, it's better to use approximation
		countries[i]->dead += dead;
		Country::total_dead += dead;
		countries[i]->sick -= dead;
		Country::total_sick -= dead;
	}
}