#include "BodyDep.h"

#include <utility>
#include "../Car.h"

using namespace eng;

void BodyDep::build(Car* car) {
	// TODO - implement BodyDep::build
	throw "Not yet implemented";
}

void BodyDep::fix(Car* car) {
	// TODO - implement BodyDep::fix
	throw "Not yet implemented";
}

void BodyDep::update(Component* component) {
	// TODO - implement BodyDep::update
	throw "Not yet implemented";
}

BodyDep::BodyDep(Department *next) : Department(next){
    departmentName = "Body Department";
}
