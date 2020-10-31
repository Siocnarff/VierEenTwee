#include "ElectricDepartment.h"
#include "ElectricHarness.h"

using namespace eng;

void ElectricDepartment::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new ElectricHarness(specialistsDesignComponent()));
    }
    Department::build(car);
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
