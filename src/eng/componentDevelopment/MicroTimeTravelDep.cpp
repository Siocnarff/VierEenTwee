#include <pr/Doc.h>
#include "MicroTimeTravelDep.h"
#include "../Car.h"
#include "Component.h"
#include "MicroInitiationPlutoniumHammer.h"

using namespace eng;

void MicroTimeTravelDep::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new MicroInitiationPlutoniumHammer(specialistsDesignComponent()));
    }
    Department::build(car);
}

void MicroTimeTravelDep::fix(Car *car) {
	if (haveSpecialists()){
		int damage = fixComponent(car, 4);
		if (damage == 0) {
			pr::Doc::detail("Micro Initiation Plutonium Hammer still functioning without anyone knowing why, sending car to next department.\n");
		} else {
			pr::Doc::detail(departmentName);
			pr::Doc::detail(" is playing with the Micro Initiation Plutonium Hammer in hope that it will work which was at ");
			pr::Doc::detail(std::to_string(damage));
			pr::Doc::detail("% damage.\n");
		}
        Department::fix(car);
	} else {
		pr::Doc::detail(departmentName);
		pr::Doc::detail(" does not have any employees and does nothing.\n");
	}
}

void MicroTimeTravelDep::update(Component* component) {
	// TODO - implement MicroTimeTravelDep::update
	throw "Not yet implemented";
}

MicroTimeTravelDep::MicroTimeTravelDep(Department *next) : Department(next) {
    departmentName = "Department of Micro-Time-Travel";
}
