#include "ElectricHarness.h"

using namespace eng;

void ElectricHarness::print() {
    std::cout   << "        Electric Harness Quality: " << getQualityLabel() << std::endl;
}

ElectricHarness::ElectricHarness(Component *toClone) : Component(toClone) {}

Component *ElectricHarness::clone() {
    return new ElectricHarness(this);
}

int ElectricHarness::getId() {
    return 2;
}
