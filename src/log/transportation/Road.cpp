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
        cout << "Container in transport via SHIP" << endl;
        cout << "From: " << fromLocation->getLocation() << " to " << destination->getLocation() << endl;
    } else if (destination == nullptr) {
        pr::Doc::detail("Container shipped to HQ from ");
        pr::Doc::detail(fromLocation->getLocation());
        pr::Doc::detail("\n");
    } else if (fromLocation == nullptr) {
        pr::Doc::detail("Container shipped from HQ to ");
        pr::Doc::detail(destination->getLocation());
        pr::Doc::detail("\n");
    } else {
        TransportHandler::transport(fromLocation, destination, car);
    }

}
