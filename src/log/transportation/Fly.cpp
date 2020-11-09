//
// Created by jo-anne on 2020/10/26.
//

#include "Fly.h"

using namespace lg;

void Fly::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (car) {
        if (fromLocation == nullptr) {
            pr::Doc::detail("     Car " + to_string(car->getId() ) +" picked up from factory and flown to ");
            pr::Doc::detail(destination->getLocation() + "\n");
        } else if (destination == nullptr) {
            pr::Doc::detail("     Car " + to_string(car->getId() ) +" picked up from ");
            pr::Doc::detail(fromLocation->getLocation());
            pr::Doc::detail(" and flown to factory\n");
        } else {
            pr::Doc::detail("     Car " + to_string(car->getId() ) + "picked up from ");
            pr::Doc::detail(fromLocation->getLocation());
            pr::Doc::detail(" and flown to ");
            pr::Doc::detail(fromLocation->getLocation() + "\n");
        }
    } else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

Fly::~Fly() {

}

