//
// Created by jo-anne on 2020/10/22.
//

#include "TransportMethods.h"

void Fly::transport(Race *fromLocation, Race *destination, Car *car) {
    if (car) {
        cout << "Car picked up from : " << fromLocation->getLocation() << "and flown to factory " << endl;
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

void Ship::transport(Race *fromLocation, Race *destination, Car *car) {
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

void Road::transport(Race *fromLocation, Race *destination, Car *car) {
        if (fromLocation->isRaceEuropean() && destination->isRaceEuropean()) {
            notify(true);
            //requestContainerChangeState(true);
            cout << "Container in transport via ROAD";
            cout << "From: " << fromLocation->getLocation() << " to " << destination->getLocation() << endl;
        }
        else {
            TransportHandler::transport(fromLocation, destination, car);
        }
}
