#include "CarState.h"
using namespace rce;
CarState * CarState::getState()
{
	return this->carState;
}

void CarState::setCarState(CarState * c)
{
	delete this->carState;
	this->carState = c;
}






