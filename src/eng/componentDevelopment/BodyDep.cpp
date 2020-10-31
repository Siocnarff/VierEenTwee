#include "BodyDep.h"

#include <utility>
#include "../Car.h"
#include "Body.h"

using namespace eng;

void BodyDep::build(Car* car) {
	if (haveSpecialists()) {
        buildComponentIntoCar(car, new Body(specialistsDesignComponent()));
	}
	Department::build(car);
}

void BodyDep::fix(Car* car, bool transparent) {
	int damage = fixComponent(car, 3);
	if (transparent) {
		if (damage == 0) {
			std::cout << "Body is still nice and streamlined, sending car to next department." << std::endl;
		} else {
			std::cout << departmentName << " is ironing out all the wrinkles which made up about " << damage << "% of the surface." << std::endl;
		}
	}
	Department::fix(car, transparent);
}

void BodyDep::update(Component* component) {
	// TODO - implement BodyDep::update
	throw "Not yet implemented";
}

BodyDep::BodyDep(Department *next) : Department(next){
    departmentName = "Body Department";
}
