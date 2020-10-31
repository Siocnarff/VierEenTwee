//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_RACINGDEPT_H
#define PREMODELLING_RACINGDEPT_H

#include <enums/WeatherConditions.h>
#include <enums/TrackComplexity.h>
#include "Car.h"
#include "races/Race.h"
#include "../../ppl/specialists/Driver.h"
#include "Strategy.h"
#include "Colleague.h"

namespace lg {
    class RacingDept : public lg::Colleague {
    public:
        void hireEmployees(int budget) override;

        Strategy *PlanSeasonStrategy(int budget);

        ppl::Driver *trainDriver(ppl::Driver *, int time, lg::WeatherConditions);

        ppl::Driver *trainDriver(ppl::Driver *, int time, TrackComplexity);

        ppl::Driver *trainDriver(ppl::Driver *, int time, WeatherConditions, TrackComplexity);

        void preRaceArrival(eng::Car *, ppl::Driver *, Race *, Container *);

        int RacingWeekend(); //as een van die karre breek, moet hy dadelik mbv notify(Car*) teruggestuur word asb.
        Container *postRacePackUp();

    private:
        eng::Car *car;
        ppl::Driver *driver;
        Container *container;
        Race *race;

    };
}

#endif //PREMODELLING_RACINGDEPT_H
