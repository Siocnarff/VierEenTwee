#include "EngineDep.h"
#include "../Car.h"
#include "Component.h"
#include "Engine.h"

using namespace eng;

void EngineDep::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new Engine(specialistsDesignComponent()));
        pr::Doc::detail("     -");
        pr::Doc::detail(departmentName);
        pr::Doc::detail(" builds and installs engine.\n");
    }
    Department::build(car);
}

void EngineDep::fix(Car *car) {
	int damage = fixComponent(car, 1);
    if (damage == 0) {
        pr::Doc::detail("     Engine still running at full power, sending car to next department.\n");
    } else {
        pr::Doc::detail("     " + departmentName);
        pr::Doc::detail(" is tuning the engine which was at ");
        pr::Doc::detail(std::to_string(100 - damage));
        pr::Doc::detail("% power.\n");
    }
    Department::fix(car);
}

void EngineDep::update(Component* component) {
	if (budget > 0) {
		budget -= rand() % 2;
	} else {
		pr::Doc::detail("     " + departmentName);
		pr::Doc::detail(" has no more funds to improve the component.\n");
		return;
	}
	pr::Doc::midInfo("     " + departmentName);
	pr::Doc::midInfo(" is tuning the engine.\n");
	Department::specialistsImproveComponent(component);
}

EngineDep::EngineDep(Department *next) : Department(next) {
    departmentName = "Engine Department";
}
