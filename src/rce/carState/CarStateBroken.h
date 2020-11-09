#ifndef CARSTATEBROKEN_H
#define CARSTATEBROKEN_H
#include <string>
#include "CarState.h"
#include "RaceWeekend.h"
namespace rce{
class CarStateBroken : public rce::CarState {

	

public:
	void handleChange();
    ~CarStateBroken();
	std::string getCarState();
};
}
#endif
