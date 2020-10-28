#ifndef RACING_CARSTATEFULLHP_H
#define RACING_CARSTATEFULLHP_H
#include "../eng/Car.h"
#include "CarState.h"
//namespace racing{
class CarStateFullHP : public CarState {


public:
	void handleChange(int i, int d);

	std::string getCarState();
};
//}
#endif
