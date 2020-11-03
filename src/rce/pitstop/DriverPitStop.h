#ifndef RACING_DRIVERPITSTOP_H
#define RACING_DRIVERPITSTOP_H
#include "../eng/Car.h"
#include "Tyres.h"
#include "RaceWeekend.h"
#include "../rce/pitstop/Pitstop.h"
namespace rce{
class DriverPitStop : public rce::Pitstop
{

public:
	eng::Car* car;
    DriverPitStop(eng::Car* c,Tyres* t);

};
}
#endif
