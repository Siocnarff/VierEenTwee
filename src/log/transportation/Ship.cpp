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
        pr::Doc::summary("  ~Container in transport via SHIP ");
        pr::Doc::summary("from: " + fromLocation->getLocation() + " to " + destination->getLocation() + "~\n");

    } else if (destination== nullptr) {
        pr::Doc::summary("  ~Container shipped to HQ~\n");
    } else if (fromLocation == nullptr) {
        pr::Doc::summary("  ~Container shipped from HQ to " + destination->getLocation() + "~\n");
    }
    else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

Ship::~Ship() {

}

