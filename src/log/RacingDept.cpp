//
// Created by jo on 2020/10/17.
//

#include "RacingDept.h"
#include <iostream>

using namespace rce;

void RacingDept::hireEmployees(int budget) {

}

rce::CreateStrategy *RacingDept::PlanSeasonStrategy(int budget) {
    throw "not yet implemented";
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
    notify(new eng::Car(2));
    std::cout << "strat packing up" << std::endl;
    notify(new log::Container);
    std::cout << "smoke a cigarette" << std::endl;

    return 5;
}


log::Container* RacingDept::postRacePackUp() { //make container*container->unpack();
    return new log::Container;

}

