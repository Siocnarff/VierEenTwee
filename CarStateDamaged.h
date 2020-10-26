#ifndef RACING_CARSTATEDAMAGED_H
#define RACING_CARSTATEDAMAGED_H
#include "../eng/Car.h"
#include "CarState.h"
namespace racing{
class CarStateDamaged : public racing::CarState {


public:
	void handleChange(eng::Car* c, int d);

	std::string getCarState();
};
}
#endif
