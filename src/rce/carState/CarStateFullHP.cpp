#include "CarStateFullHP.h"
#include "CarStateDamaged.h"
#include <iostream>
using namespace rce;
void CarStateFullHP::handleChange( ) {
		setCarState(new CarStateDamaged());
		//std::cout << "Here" << std::endl;
	
}

std::string CarStateFullHP::getCarState() {
	return "FullHP";
}

CarStateFullHP::~CarStateFullHP()
{

}