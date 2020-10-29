//
// Created by jo-anne on 2020/10/26.
//

#include "Fly.h"
using namespace log;

void Fly::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (fromLocation == nullptr) {
        std::cout << "Car picked up from factory and flown to " << destination->getLocation() << std::endl;
    } else if (car) {
        std::cout << "Car picked up from : " << fromLocation->getLocation() << "and flown to factory " << std::endl;
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

