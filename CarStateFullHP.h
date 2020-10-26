#ifndef RACING_CARSTATEFULLHP_H
#define RACING_CARSTATEFULLHP_H
#include "../eng/Car.h"
#include "CarState.h"
namespace racing{
class CarStateFullHP : public racing::CarState {


public:
	void handleChange(eng::Car* c, int d);

	std::string getCarState();
};
}
#endif
