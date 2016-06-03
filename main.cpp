#include <iostream>
#include <ostream>
#include <unistd.h>
#include <time.h>

#include "Pathogen.h"
#include "Country.h"
#include "Interface.h"

using namespace std;

#define INTERFACE Interface::get_interface()

int main() {
	srand(time(NULL));
	vector <Country *> countries = Country::init();
	Pathogen * pathogen = new Pathogen(5,5,10); //entering stats
	countries[24]->sick = 1; //choosing patient zero

	INTERFACE.clear();
	INTERFACE.init_draw();

	bool end = false;
	int day = 1;
	while (!end) {
		pathogen->spread_locally(countries);
		pathogen->kill(countries);
		if (Country::total_spread < countries.size()) pathogen->spread_globally(countries);
		INTERFACE.draw(day, Country::total_spread, countries.size(), Country::total_sick, Country::total_dead, Country::total_population, countries);
		if (Country::total_sick == 0) break;
		day++;
		usleep(50000);
	}
	INTERFACE.write("#################\nKoniec symulacji\n", 0, countries.size() + 5);
}