//
// Created by jo-anne on 2020/10/26.
//

#include "Fly.h"
using namespace lg;

void Fly::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (car) {
        cout << "Car picked up from : " << fromLocation->getLocation() << "and flown to factory " << endl;
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

