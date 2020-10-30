//
// Created by jo on 2020/10/17.
//

#include "Colleague.h"
#include "Mediator.h"
using namespace log;

Colleague::~Colleague() = default;

void Colleague::addObserver(Mediator *obs) {
    logisticsDep = obs;
}

void Colleague::notify(eng::Car *car) {
    logisticsDep->sendCarToFactory(car);
}

void Colleague::notify(Container *container) {
    logisticsDep->containerHasBeenPacked(container);
}

void Colleague::notify(bool isEuropeanRace) {
    logisticsDep->requestContainerStateChange(isEuropeanRace);
}
