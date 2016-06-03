#pragma once

#include "Country.h"

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Interface {
private:
	Interface() {}
	Interface(const Interface&);
public:
	static Interface& get_interface() {
		static Interface interface;
		return interface;
	}
	void clear();
	void write(string interface, int x, int y);
	void write(int interface, int x, int y);
	void draw(int day, int total_spread, int total_countries, unsigned int total_sick, unsigned int total_dead, int total_population, vector <Country *> countries);
	void init_draw();
};