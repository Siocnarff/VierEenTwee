#include "ElectricDepartment.h"

using namespace eng;

void ElectricDepartment::build(Car* car) {
	// TODO - implement ElectricDepartment::build
	throw "Not yet implemented";
}

void ElectricDepartment::fix(Car* car, bool transparent) {
	int damage = fixComponent(car, 2);
	if (transparent) {
		if (damage == 0) {
			std::cout << "All the shocks came from the correct wires, sending car to next department." << std::endl;
		} else {
			std::cout << departmentName << " is rewiring the harness which took " << damage << "% damage." << std::endl;
		}
	}
	Department::fix(car, transparent);
}

void ElectricDepartment::update(Component* component) {
	// TODO - implement ElectricDepartment::update
	throw "Not yet implemented";
}

ElectricDepartment::ElectricDepartment(Department *next) : Department(next) {
    departmentName = "Electric Department";
}
