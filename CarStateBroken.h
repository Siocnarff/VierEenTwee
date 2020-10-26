#ifndef RACING_CARSTATEBROKEN_H
#define RACING_CARSTATEBROKEN_H
#include "../eng/Car.h"
#include "CarState.h"
namespace racing{
class CarStateBroken : public racing::CarState {


public:
	void handleChange(eng::Car* c, int d);

	std::string getCarState();
};
}
#endif
