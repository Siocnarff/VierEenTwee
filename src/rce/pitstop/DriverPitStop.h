#ifndef RACING_DRIVERPITSTOP_H
#define RACING_DRIVERPITSTOP_H
//#include "../eng/Car.h"
//#include "Tires.h"
#include "RaceWeekend.h"
#include "Pitstop.h"

namespace rce {
    class DriverPitStop : public Pitstop {

    public:
        eng::Car *car;

        void tyres(Tyres *t);

        void setCar(eng::Car *car);

        void race();
    };
}
#endif
