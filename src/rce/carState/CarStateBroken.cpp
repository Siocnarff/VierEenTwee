#include "CarStateBroken.h"

void CarStateBroken::handleChange(int i, int d) {
	setDamage(getDamage + d);
	if(getDamage() >=90)
	{
		race->NotifyCar();
	}
}

std::string CarStateBroken::getCarState() {
	return "Broken";
}
