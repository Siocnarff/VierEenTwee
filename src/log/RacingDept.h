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
#include "Colleague.h"
#include "Strategy.h"

namespace rce {
    class RacingDept : public log::Colleague {
    public:
        void hireEmployees(int budget) override;

        Strategy *PlanSeasonStrategy(int budget);

        ppl::Driver *trainDriver(ppl::Driver *, int time, log::WeatherConditions);

        ppl::Driver *trainDriver(ppl::Driver *, int time, log::TrackComplexity);

        ppl::Driver *trainDriver(ppl::Driver *, int time, log::WeatherConditions, log::TrackComplexity);

        void preRaceArrival(eng::Car *, ppl::Driver *, log::Race *, log::Container *);

        int RacingWeekend(); //as een van die karre breek, moet hy dadelik mbv notify(Car*) teruggestuur word asb.
        log::Container *postRacePackUp();

    private:
        eng::Car *car;
        ppl::Driver *driver;
        log::Container *container;
        log::Race *race;

    };
}

#endif //PREMODELLING_RACINGDEPT_H
