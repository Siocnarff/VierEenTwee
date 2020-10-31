#include <pr/Doc.h>
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
    if (damage == 0) {
        pr::Doc::detail("Chassis was not damaged, sending car to next department.\n");
    } else {
        pr::Doc::detail(departmentName);
        pr::Doc::detail(" is fixing the chassis which was at ");
        pr::Doc::detail(std::to_string(damage));
        pr::Doc::detail("% damage.\n");
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
