#include "CarStateDamaged.h"
#include "CarStateBroken.h"
using namespace rce;
void CarStateDamaged::handleChange() {

	setCarState(new CarStateBroken());
}

std::string CarStateDamaged::getCarState() {
	return "Damaged";
}

CarStateDamaged::~CarStateDamaged()
{

}