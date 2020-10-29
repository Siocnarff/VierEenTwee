//
// Created by jo-anne on 2020/10/22.
//

#include "Road.h"
using namespace log;



void Road::transport(Race *fromLocation, Race *destination, eng::Car *car) {
        if (fromLocation->isRaceEuropean() && destination->isRaceEuropean()) {
            notify(true);
            //requestContainerChangeState(true);
            std::cout << "Container in transport via ROAD";
            std::cout << "From: " << fromLocation->getLocation() << " to " << destination->getLocation() << std::endl;
        }
        else {
            TransportHandler::transport(fromLocation, destination, car);
        }
}
