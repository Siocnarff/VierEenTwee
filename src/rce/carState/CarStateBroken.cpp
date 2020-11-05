#include "CarStateBroken.h"
#include <iostream>
using namespace rce;
void CarStateBroken::handleChange() {
	std::cout << "The car is broken" << std::endl;
}

std::string CarStateBroken::getCarState() {
	return "Broken";
}
