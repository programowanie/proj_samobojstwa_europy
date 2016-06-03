#pragma once

#include "Country.h"

#include <vector>
#include <iterator>

class Pathogen {
	private:
		int _contagiousness; // 1-10 scale
		int _resistance; //1-10 scale
		int _progressionSpeed; //1-10 scale
	public:
		Pathogen(int contagiousness, int resistance, int progressionSpeed);
		int get_contagiousness();
		int get_resistance();
		int get_progressionSpeed();

		void spread_locally(vector <Country *> countries);
		void spread_globally(vector <Country *> countries);
		void kill(vector <Country *> countries);
};