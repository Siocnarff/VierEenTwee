#include "ChassisDep.h"
#include "Chassis.h"

using namespace eng;

void ChassisDep::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new Chassis(specialistsDesignComponent()));
    }
    Department::build(car);
}

void ChassisDep::fix(Car *car) {
	int damage = fixComponent(car, 0);
	if (transparent) {
		if (damage == 0) {
			std::cout << "Chassis was not damaged, sending car to next department." << std::endl;
		} else {
			std::cout << departmentName << " is fixing the chassis which was at " << damage << "% damage." << std::endl;
		}
	}
    Department::fix(car);
}

void ChassisDep::update(Component* component) {
	// TODO - implement ChassisDep::update
	throw "Not yet implemented";
}

ChassisDep::ChassisDep(Department *next) : Department(next) {
    departmentName = "Chassis Department";
}
