#ifndef CARSTATEFULLHP_H
#define CARSTATEFULLHP_H
#include "Car.h"
#include "CarState.h"
#include <string>
using namespace std;
class CarStateFullHP : public CarState {


public:
	void handleChange(Car* c, int d);

	string getCarState();
};

#endif
