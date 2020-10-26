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

using namespace log;

class RacingDept : public Colleague {
public:
    void HireEmployees(int budget) override;
    Strategy* PlanSeasonStrategy(int budget);
    Driver *trainDriver(Driver *, int time, WeatherConditions);
    Driver* trainDriver(Driver *, int time, TrackComplexity);
    Driver* trainDriver(Driver *, int time, WeatherConditions, TrackComplexity);
    void preRaceArrival(Car*, Driver*, Race*, Container*);
    int RacingWeekend(); //as een van die karre breek, moet hy dadelik mbv notify(Car*) teruggestuur word asb.
    Container* postRacePackUp();

private:
    Car* car;
    Driver* driver;
    Container* container;
    Race* race;

};

#endif //PREMODELLING_RACINGDEPT_H
