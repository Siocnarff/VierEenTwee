//
// Created by jo-anne on 2020/10/22.
//

#include "Road.h"

using namespace lg;


void Road::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (car != nullptr) {
        TransportHandler::transport(fromLocation, destination, car);
    } else if (fromLocation != nullptr && destination != nullptr && fromLocation->isRaceEuropean() && destination->isRaceEuropean()) { //races will only be null if transporting car, so no segfault here
        //ship and change state etc
        notify(destination->isRaceEuropean());
        //requestContainerChangeState(destination->isRaceEuropean());
        pr::Doc::detail("     Container in transport via ROAD from: " + fromLocation->getLocation() + " to " + destination->getLocation() + "\n");
    } else if (destination == nullptr) {
        pr::Doc::detail("     Confirmed that container has been shipped to HQ from " + fromLocation->getLocation() + "\n");
    } else if (fromLocation == nullptr) {
        pr::Doc::detail("     Confirmed that container has been shipped from HQ to " + destination->getLocation() + "\n");
    } else {
        TransportHandler::transport(fromLocation, destination, car);
    }

}

Road::~Road() {

}
