#include "Chassis.h"

using namespace eng;

void Chassis::print() {
    pr::Doc::detail("\t\tChassis Quality: " + std::to_string(getQualityLabel()) + "\n");
}

Chassis::Chassis(Component *toClone) : Component(toClone) {}

Component *Chassis::clone() {
    return new Chassis(this);
}

int Chassis::getId() {
    return 0;
}

Chassis::Chassis(int quality) : Component(quality) {

}
