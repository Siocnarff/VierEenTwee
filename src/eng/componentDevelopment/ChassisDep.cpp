#include "ChassisDep.h"
#include "Chassis.h"

using namespace eng;

void ChassisDep::build(Car* car) {
    if (haveSpecialists()) {
        buildComponentIntoCar(car, new Chassis(specialistsDesignComponent()));
        pr::Doc::detail("     -");
        pr::Doc::detail(departmentName);
        pr::Doc::detail(" builds a new chassis for car.\n");
    }
    Department::build(car);
}

void ChassisDep::fix(Car *car) {
	int damage = fixComponent(car, 0);
    if (damage == 0) {
        pr::Doc::detail("     Chassis was not damaged, sending car to next department.\n");
    } else {
        pr::Doc::detail("     " + departmentName);
        pr::Doc::detail(" is fixing the chassis which was at ");
        pr::Doc::detail(std::to_string(damage));
        pr::Doc::detail("% damage.\n");
    }
    Department::fix(car);
}

void ChassisDep::update(Component* component) {
	if (budget > 0) {
		budget -= rand() % 2;
	} else {
		pr::Doc::detail("     " + departmentName);
		pr::Doc::detail(" has no more funds to improve the component.\n");
		return;
	}
	pr::Doc::midInfo("     " + departmentName);
	pr::Doc::midInfo(" is improving the chassis.\n");
	Department::specialistsImproveComponent(component);
}

ChassisDep::ChassisDep(Department *next) : Department(next) {
    departmentName = "Chassis Department";
}
