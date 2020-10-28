//
// Created by jo on 2020/10/17.
//

#include "RacingDept.h"
#include <iostream>

void RacingDept::hireEmployees(int budget) {

}

Strategy *RacingDept::PlanSeasonStrategy(int budget) {
    return new Strategy(budget);
}


ppl::Driver * RacingDept::trainDriver(ppl::Driver*, int time, WeatherConditions, TrackComplexity){
    return nullptr;
}

ppl::Driver *RacingDept::trainDriver(ppl::Driver *, int time, WeatherConditions) {
    return nullptr;
}

ppl::Driver *RacingDept::trainDriver(ppl::Driver *, int time, TrackComplexity) {
    return nullptr;
}


void RacingDept::preRaceArrival(eng::Car *c, ppl::Driver *d, Race *r, Container *con) {
    std::cout << "arrive at destination" << endl;
    car  = c;
    driver = d;
    race = r;
    container = con;
}

int RacingDept::RacingWeekend() {
    std::cout << "Let's start"<<endl;
    notify(new eng::Car);
    std::cout << "strat packing up" << endl;
    notify(new Container);
    std::cout << "smoke a cigarette" << endl;

    return 5;
}

Container* RacingDept::postRacePackUp() { //make container*
    std::cout << container->getState();
    container->unpack();
    container->advanceState();
    std::cout << container->getState();


}

