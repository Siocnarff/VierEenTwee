//
// Created by jo-anne on 2020/10/26.
//

#include "Ship.h"
using namespace lg;

void Ship::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (car!=nullptr){
        TransportHandler::transport(fromLocation, destination, car);
    } else if (fromLocation != nullptr && destination!= nullptr && (!fromLocation->isRaceEuropean() || !destination->isRaceEuropean())) {
        //ship and change state etc
        notify(destination->isRaceEuropean());
        //requestContainerChangeState(destination->isRaceEuropean());
        pr::Doc::detail("Container in transport via SHIP");
        pr::Doc::detail("From: " + fromLocation->getLocation() + " to " + destination->getLocation());

    } else if (destination== nullptr) {
        pr::Doc::detail("Container shipped to HQ");
        pr::Doc::detail("\n");
    } else if (fromLocation == nullptr) {
        pr::Doc::detail("Container shipped from HQ to ");
        pr::Doc::detail(destination->getLocation());
        pr::Doc::detail("\n");
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

Ship::~Ship() {

}

