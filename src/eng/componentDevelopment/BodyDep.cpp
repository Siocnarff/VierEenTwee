#include "BodyDep.h"

#include <utility>
#include "../Car.h"
#include "Body.h"

using namespace eng;

void BodyDep::build(Car* car) {
	if (haveSpecialists()) {
        buildComponentIntoCar(car, new Body(specialistsDesignComponent()));
        pr::Doc::detail("     -");
        pr::Doc::detail(departmentName);
        pr::Doc::detail(" is building a new body for car.\n");
	}
	Department::build(car);
}

void BodyDep::fix(Car *car) {
	int damage = fixComponent(car, 3);
    if (damage == 0) {
        pr::Doc::detail("     Body is still nice and streamlined, sending car to next department.\n");
    } else {
        pr::Doc::detail("     " + departmentName);
        pr::Doc::detail(" is ironing out all the wrinkles which made up about ");
        pr::Doc::detail(std::to_string(damage));
        pr::Doc::detail("% of the surface.\n");
    }
    Department::fix(car);
}

void BodyDep::update(Component* component) {
	if (budget > 0) {
		budget -= rand() % 2;
	} else {
		pr::Doc::detail("     " + departmentName);
		pr::Doc::detail(" has no more funds to improve the component.\n");
		return;
	}
	pr::Doc::midInfo("     " + departmentName);
	pr::Doc::midInfo(" is using poly filler to streamline the body.\n");
	Department::specialistsImproveComponent(component);
}

BodyDep::BodyDep(Department *next) : Department(next){
    departmentName = "Body Department";
}
