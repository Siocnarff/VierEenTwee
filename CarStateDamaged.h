#ifndef CARSTATEDAMAGED_H
#define CARSTATEDAMAGED_H
#include "Car.h"
#include "CarState.h"
#include <string>
using namespace std;
class CarStateDamaged : public CarState {


public:
	void handleChange(Car* c, int d);

	string getCarState();
};

#endif
