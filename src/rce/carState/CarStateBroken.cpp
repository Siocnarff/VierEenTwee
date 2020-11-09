#include "CarStateBroken.h"
#include <iostream>
using namespace rce;
void CarStateBroken::handleChange() {
	pr::Doc::detail("The car is broken");
}

std::string CarStateBroken::getCarState() {
	return "Broken";
}
