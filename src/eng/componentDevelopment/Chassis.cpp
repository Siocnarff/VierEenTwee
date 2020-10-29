#include "Chassis.h"

using namespace eng;

void Chassis::print() {
	std::cout << "Chassis" << std::endl;
}

Chassis::Chassis(Component *toClone) : Component(toClone) {}

Component *Chassis::clone() {
    return new Chassis(this);
}
