#include "MicroTimeTravelDep.h"
#include "../Car.h"
#include "Component.h"

using namespace eng;

void MicroTimeTravelDep::build(Car* car) {
	// TODO - implement MicroTimeTravelDep::build
	throw "Not yet implemented";
}

void MicroTimeTravelDep::fix(Car* car, bool transparent) {
	if (haveSpecialists()){
		int damage = fixComponent(car, 4);
		if (transparent) {
			if (damage == 0) {
				std::cout << "Micro Initiation Plutonium Hammer still functioning without anyone knowing why, sending car to next department." << std::endl;
			} else {
				std::cout << departmentName << " is playing with the Micro Initiation Plutonium Hammer in hope that it will work which was at " << damage << "% damage." << std::endl;
			}
		}
		Department::fix(car, transparent);
	} else {
		if (transparent) {
			std::cout << departmentName << " does not have any employees and does nothing." << std::endl;
		}
	}

}

void MicroTimeTravelDep::update(Component* component) {
	// TODO - implement MicroTimeTravelDep::update
	throw "Not yet implemented";
}

MicroTimeTravelDep::MicroTimeTravelDep(Department *next) : Department(next) {
    departmentName = "Department of Micro-Time-Travel";
}
