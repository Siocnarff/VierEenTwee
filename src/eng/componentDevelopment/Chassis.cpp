#include "Chassis.h"

using namespace eng;

void Chassis::print() {
    std::cout   << "        Chassis Quality: " << getQualityLabel() << std::endl;
}

Chassis::Chassis(Component *toClone) : Component(toClone) {}

Component *Chassis::clone() {
    return new Chassis(this);
}

int Chassis::getId() {
    return 0;
}
