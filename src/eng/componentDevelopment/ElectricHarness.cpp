#include "ElectricHarness.h"

using namespace eng;

void ElectricHarness::print() {
	std::cout << "Electric Harness" << std::endl;
}

ElectricHarness::ElectricHarness(Component *toClone) : Component(toClone) {}

Component *ElectricHarness::clone() {
    return new ElectricHarness(this);
}
