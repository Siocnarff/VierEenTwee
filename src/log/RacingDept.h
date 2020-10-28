//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_RACINGDEPT_H
#define PREMODELLING_RACINGDEPT_H

#include "Car.h"
#include "Race.h"
#include "Driver.h"
#include "Strategy.h"
#include "Colleague.h"


class RacingDept : public log::Colleague {
public:
    void HireEmployees(int budget) override;
    Strategy* PlanSeasonStrategy(int budget);
    ppl::Driver* trainDriver(ppl::Driver *, int time, WeatherConditions);
    ppl::Driver* trainDriver(ppl::Driver *, int time, TrackComplexity);
    ppl::Driver* trainDriver(ppl::Driver *, int time, WeatherConditions, TrackComplexity);
    void preRaceArrival(eng::Car*, ppl::Driver*, Race*, Container*);
    int RacingWeekend(); //as een van die karre breek, moet hy dadelik mbv notify(Car*) teruggestuur word asb.
    Container* postRacePackUp();

private:
    eng::Car* car;
    ppl::Driver* driver;
    Container* container;
    Race* race;

};

#endif //PREMODELLING_RACINGDEPT_H
