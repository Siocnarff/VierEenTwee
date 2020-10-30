#ifndef RACING_DRIVERPITSTOP_H
#define RACING_DRIVERPITSTOP_H
//#include "../eng/Car.h"
//#include "Tires.h"
#include "RaceWeekend.h"

namespace rce {
    class DriverPitStop : public racing::Pitstop {

    public:
        eng::Car *car;

        void tyres(racing::Tires *t);

        void setCar(eng::Car *car);

        //void race();
    };
}
#endif
