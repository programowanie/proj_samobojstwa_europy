#include "Interface.h"

void Interface::clear() {
	printf("\E[H\E[2J");
	fflush(stdout);
}

void Interface::write(string output, int x, int y) {
	printf("\033[%d;%dH%s   ", y, x, output.c_str()); //few white spaces to cover characters from previous "frames"
	fflush(stdout);
}

void Interface::write(int output, int x, int y) {
	printf("\033[%d;%dH%d", y, x, output);
	fflush(stdout);
}

void Interface::draw(int day, int total_spread, int total_countries, unsigned int total_sick, unsigned int total_dead, int total_population, vector <Country *> countries) {
	string text;

	write(day, 8, 4);

	text = to_string(total_spread) + "/" + to_string(total_countries);
	write(text, 23, 4);

	text = to_string(total_sick) + "/" + to_string(total_population);
	write(text, 44, 4);

	text = to_string(total_dead) + "/" + to_string(total_population);
	write(text, 80, 4);

	for (int j = 0; j < (signed)countries.size(); j++) {
		write(
			countries[j]->get_name() +  ": " + to_string(countries[j]->sick) + "/" + to_string(countries[j]->dead) + "/" + to_string(countries[j]->get_population()),
			0,
			5+j);
	}
}

void Interface::init_draw() {
	write("Samobójstwo Europy", 1, 1);
	write("Symulator epidemii", 1, 2);
	write("Dzień: ", 1, 4);
	write("Rozwój: ", 15, 4);
	write("Zarażonych: ", 32, 4);
	write("Zmarłych: ", 70, 4);
}