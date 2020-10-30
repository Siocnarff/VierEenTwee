//
// Created by jo on 2020/10/17.
//

#include "Colleague.h"
#include "Mediator.h"
using namespace log;

Colleague::~Colleague() = default;

void Colleague::addObserver(Mediator *obs) {
    logistcsDep = obs;
}

void Colleague::notify(eng::Car *car) {
    logistcsDep->sendCarToFactory(car);
}

void Colleague::notify(Container *container) {
    logistcsDep->containerHasBeenPacked(container);
}

void Colleague::notify(bool isEuropeanRace) {
    logistcsDep->requestContainerStateChange(isEuropeanRace);
}