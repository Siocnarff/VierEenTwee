#ifndef CARSTATEDAMAGED_H
#define CARSTATEDAMAGED_H
#include "CarState.h"
namespace rce{
class CarStateDamaged : public rce::CarState {


public:
	void handleChange();

	std::string getCarState();
};
}
#endif
