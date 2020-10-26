#ifndef CARSTATEBROKEN_H
#define CARSTATEBROKEN_H
#include "Car.h"
#include "CarState.h"
#include <string>
using namespace std;
class CarStateBroken : public CarState {


public:
	void handleChange(Car* c, int d);

	string getCarState();
};

#endif
