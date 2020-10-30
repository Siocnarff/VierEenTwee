//
// Created by jo-anne on 2020/10/26.
//

#include "Ship.h"
using namespace log;

void Ship::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (fromLocation->isRaceEuropean()!=destination->isRaceEuropean()) {
        //ship and change state etc
        notify(destination->isRaceEuropean());
        //requestContainerChangeState(destination->isRaceEuropean());
        std::cout << "Container in transport via SHIP" << std::endl;
        std::cout << "From: " << fromLocation->getLocation() << " to " << destination->getLocation() << std::endl;
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

Ship::Ship(Mediator *mediator) : TransportHandler(mediator) {}

