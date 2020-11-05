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

void Colleague::notify(std::vector<eng::Car *>cars, Race* r) {
    logisticsDept->sendCarToFactory(cars, r, false);
}

void Colleague::notify(eng::Car *broken, Race *r) {
    std::vector<eng::Car*> brokenCar;
    brokenCar.push_back(broken);
    logisticsDept->sendCarToFactory(brokenCar, r, true);
}


/*void Colleague::notify(Container *container) {
    logisticsDept->containerHasBeenPacked(container);
}*/

void Colleague::notify(bool isEuropeanRace) {
    //logisticsDept->requestContainerStateChange(isEuropeanRace);
    if (isEuropeanRace) {
        pr::Doc::summary("Transportation in Europe\n");
    } else {
        pr::Doc::summary("Transportation outside of Europe\n");
    }

}

void Colleague::notify(int* tyreOrder) {
    logisticsDept->orderTyres(tyreOrder);
}

void Colleague::flyDriversBack(std::vector<ppl::Driver*> drivers) {
    logisticsDept->moveDrivers(drivers);
}
