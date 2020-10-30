//
// Created by jo on 2020/10/17.
//

#include "RacingDept.h"
#include <iostream>

using namespace rce;

RacingDept::RacingDept(log::Mediator *mediator) : Colleague(mediator) {}

void RacingDept::hireEmployees(int budget) {

}

Strategy *RacingDept::PlanSeasonStrategy(int budget) {
    return new Strategy(budget);
}


ppl::Driver * RacingDept::trainDriver(ppl::Driver*, int time, log::WeatherConditions, log::TrackComplexity){
    return nullptr;
}

ppl::Driver *RacingDept::trainDriver(ppl::Driver *, int time, log::WeatherConditions) {
    return nullptr;
}

ppl::Driver *RacingDept::trainDriver(ppl::Driver *, int time, log::TrackComplexity) {
    return nullptr;
}


void RacingDept::preRaceArrival(eng::Car *c, ppl::Driver *d, log::Race *r, log::Container *con) {
    std::cout << "arrive at destination" << std::endl;
    car  = c;
    driver = d;
    race = r;
    container = con;
}

int RacingDept::RacingWeekend() {
    std::cout << "Let's start"<<std::endl;
    notify(new eng::Car(0));
    std::cout << "strat packing up" << std::endl;
    notify(new log::Container);
    std::cout << "smoke a cigarette" << std::endl;

    return 5;
}

log::Container* RacingDept::postRacePackUp() { //make container*
    std::cout << container->getState();
    container->unpack();
    container->advanceState();
    std::cout << container->getState();
    return new log::Container;


}
