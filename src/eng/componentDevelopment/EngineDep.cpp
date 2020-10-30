#include "EngineDep.h"
#include "../Car.h"
#include "Component.h"

using namespace eng;

void EngineDep::build(Car* car) {
	// TODO - implement EngineDep::build
	throw "Not yet implemented";
}

void EngineDep::fix(Car* car, bool transparent) {
	int damage = fixComponent(car, 1);
	if (transparent) {
		if (damage == 0) {
			std::cout << "Engine still running at full power, sending car to next department." << std::endl;
		} else {
			std::cout << departmentName << " is tuning the engine which was at " << 100 - damage << "% power." << std::endl;
		}
	}
	Department::fix(car, transparent);
}

void EngineDep::update(Component* component) {
	// TODO - implement EngineDep::update
	throw "Not yet implemented";
}

EngineDep::EngineDep(Department *next) : Department(next) {
    departmentName = "Engine Department";
}
