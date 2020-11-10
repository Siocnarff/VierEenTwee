#include "MicroTimeTravelDep.h"
#include "../Car.h"
#include "Component.h"
#include "MicroInitiationPlutoniumHammer.h"

using namespace eng;

void MicroTimeTravelDep::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new MicroInitiationPlutoniumHammer(specialistsDesignComponent()));
        pr::Doc::detail("     -");
        pr::Doc::detail(departmentName);
        pr::Doc::detail(" secretly installs plutonium hammer in car.\n");
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
	} else {
		pr::Doc::detail(departmentName);
		pr::Doc::detail(" does not have any employees and does nothing.\n");
	}
	Department::fix(car);
}

void MicroTimeTravelDep::update(Component* component) {
	if (budget > 0) {
		budget -= rand() % 2;
	} else {
		pr::Doc::detail(departmentName);
		pr::Doc::detail(" has no more funds to improve the component.\n");
		return;
	}
	pr::Doc::detail(departmentName);
	pr::Doc::detail(" is replacing and improving the flux capacitor within the Micro Initiation Plutonium Hammer hoping it will improve performance.\n");
	Department::specialistsImproveComponent(component);
}

MicroTimeTravelDep::MicroTimeTravelDep(Department *next) : Department(next) {
    departmentName = "Department of Micro-Time-Travel";
}
