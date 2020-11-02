//
// Created by jo on 2020/10/17.
//

#include "Colleague.h"
#include "Mediator.h"
using namespace lg;

Colleague::~Colleague() = default;

void Colleague::addObserver(Mediator *obs) {
    logisticsDept = obs;
}

void Colleague::notify(eng::Car *car, Race* r) {
    logisticsDept->sendCarToFactory(car, r);
}

void Colleague::notify(Container *container) {
    logisticsDept->containerHasBeenPacked(container);
}

void Colleague::notify(bool isEuropeanRace) {
    //logisticsDept->requestContainerStateChange(isEuropeanRace);
    if (isEuropeanRace) {
        std::cout << "Transportation in Europe\n";
    } else {
        std::cout << "Transportation outside of Europe\n";
    }

}

void Colleague::notify(int *tyreOrder) {
    logisticsDept->orderTyres(tyreOrder);

}
