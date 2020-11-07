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
        pr::Doc::summary("Container in transport via ROAD");
        pr::Doc::summary("From: " + fromLocation->getLocation() + " to " + destination->getLocation());
    } else if (destination == nullptr) {
        pr::Doc::summary("Container shipped to HQ from ");
        pr::Doc::summary(fromLocation->getLocation());
        pr::Doc::summary("\n");
    } else if (fromLocation == nullptr) {
        pr::Doc::summary("Container shipped from HQ to ");
        pr::Doc::summary(destination->getLocation());
        pr::Doc::summary("\n");
    } else {
        TransportHandler::transport(fromLocation, destination, car);
    }

}

Road::~Road() {

}
