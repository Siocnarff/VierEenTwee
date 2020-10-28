#include "ChassisDep.h"

using namespace eng;

void ChassisDep::build(Car* car) {
	// TODO - implement ChassisDep::build
	throw "Not yet implemented";
}

void ChassisDep::fix(Car* car) {
	// TODO - implement ChassisDep::fix
	throw "Not yet implemented";
}

void ChassisDep::update(Component* component) {
	// TODO - implement ChassisDep::update
	throw "Not yet implemented";
}

ChassisDep::ChassisDep(Department *next) : Department(next) {
    departmentName = "Chassis Department";
}
