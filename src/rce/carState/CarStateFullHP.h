#ifndef CARSTATEFULLHP_H
#define CARSTATEFULLHP_H
#include "RaceWeekend.h"
#include "CarState.h"
namespace rce{
class CarStateFullHP : public rce::CarState
        {


public:
	void handleChange();

	std::string getCarState();
};
}
#endif
