//
// Created by jo-anne on 2020/10/22.
//

#include "Road.h"
using namespace lg;



void Road::transport(Race *fromLocation, Race *destination, eng::Car *car) {
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
