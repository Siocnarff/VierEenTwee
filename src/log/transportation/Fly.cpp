//
// Created by jo-anne on 2020/10/26.
//

#include "Fly.h"

using namespace lg;

void Fly::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (car) {
        if (fromLocation == nullptr) {
            pr::Doc::detail("Car picked up from factory and flow to ");
            pr::Doc::detail(destination->getLocation());
        } else if (destination == nullptr) {
            pr::Doc::detail("Car picked up from ");
            pr::Doc::detail(fromLocation->getLocation());
            pr::Doc::detail(" and flown to factory");
        } else {
            pr::Doc::detail("Car picked up from ");
            pr::Doc::detail(fromLocation->getLocation());
            pr::Doc::detail(" and flown to ");
            pr::Doc::detail(fromLocation->getLocation());
        }
    } else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

