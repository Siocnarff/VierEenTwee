//
// Created by jo-anne on 2020/10/26.
//

#include "Ship.h"
using namespace lg;

void Ship::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (fromLocation->isRaceEuropean()!=destination->isRaceEuropean()) {
        //ship and change state etc
        notify(destination->isRaceEuropean());
        //requestContainerChangeState(destination->isRaceEuropean());
        cout << "Container in transport via SHIP" << endl;
        cout << "From: " << fromLocation->getLocation() << " to " << destination->getLocation() << endl;
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

