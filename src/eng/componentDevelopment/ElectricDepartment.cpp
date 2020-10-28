#include "ElectricDepartment.h"

using namespace eng;

void ElectricDepartment::build(Car* car) {
	// TODO - implement ElectricDepartment::build
	throw "Not yet implemented";
}

void ElectricDepartment::fix(Car* car) {
	// TODO - implement ElectricDepartment::fix
	throw "Not yet implemented";
}

void ElectricDepartment::update(Component* component) {
	// TODO - implement ElectricDepartment::update
	throw "Not yet implemented";
}

ElectricDepartment::ElectricDepartment(Department *next) : Department(next) {
    departmentName = "Electric Department";
}
