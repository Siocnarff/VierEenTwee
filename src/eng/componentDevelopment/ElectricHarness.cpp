#include "ElectricHarness.h"

using namespace eng;

void ElectricHarness::print() {
    pr::Doc::detail("\tElectric Harness Quality: " + std::to_string(getQualityLabel()));
}

ElectricHarness::ElectricHarness(Component *toClone) : Component(toClone) {}

Component *ElectricHarness::clone() {
    return new ElectricHarness(this);
}

int ElectricHarness::getId() {
    return 2;
}

ElectricHarness::ElectricHarness(int quality) : Component(quality) {

}
