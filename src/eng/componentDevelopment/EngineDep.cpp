#include <pr/Doc.h>
#include "EngineDep.h"
#include "../Car.h"
#include "Component.h"
#include "Engine.h"

using namespace eng;

void EngineDep::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new Engine(specialistsDesignComponent()));
    }
    Department::build(car);
}

void EngineDep::fix(Car *car) {
	int damage = fixComponent(car, 1);
    if (damage == 0) {
        pr::Doc::detail("Engine still running at full power, sending car to next department.\n");
    } else {
        pr::Doc::detail(departmentName);
        pr::Doc::detail(" is tuning the engine which was at ");
        pr::Doc::detail(std::to_string(100 - damage));
        pr::Doc::detail("% power.\n");
    }
    Department::fix(car);
}

void EngineDep::update(Component* component) {
	// TODO - implement EngineDep::update
	throw "Not yet implemented";
}

EngineDep::EngineDep(Department *next) : Department(next) {
    departmentName = "Engine Department";
}
