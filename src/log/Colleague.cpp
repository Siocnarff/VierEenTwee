//
// Created by jo on 2020/10/17.
//

#include "Colleague.h"
#include "Mediator.h"
using namespace log;

Colleague::~Colleague() = default;

void Colleague::addObserver(Mediator *obs) {
    logisticsDept = obs;
}

void Colleague::notify(eng::Car *car) {
    logisticsDept->sendCarToFactory(car);
}

void Colleague::notify(Container *container) {
    logisticsDept->containerHasBeenPacked(container);
}

void Colleague::notify(bool isEuropeanRace) {
    logisticsDept->requestContainerStateChange(isEuropeanRace);
}