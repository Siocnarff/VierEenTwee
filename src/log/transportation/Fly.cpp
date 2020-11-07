//
// Created by jo-anne on 2020/10/26.
//

#include "Fly.h"

using namespace lg;

void Fly::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (car) {
        if (fromLocation == nullptr) {
            pr::Doc::summary("Car " + to_string(car->getId() ) +" picked up from factory and flow to ");
            pr::Doc::summary(destination->getLocation() + "\n");
        } else if (destination == nullptr) {
            pr::Doc::summary("Car " + to_string(car->getId() ) +" picked up from ");
            pr::Doc::summary(fromLocation->getLocation());
            pr::Doc::summary(" and flown to factory\n");
        } else {
            pr::Doc::summary("Car " + to_string(car->getId() ) + "picked up from ");
            pr::Doc::summary(fromLocation->getLocation());
            pr::Doc::summary(" and flown to ");
            pr::Doc::summary(fromLocation->getLocation() + "\n");
        }
    } else {
        TransportHandler::transport(fromLocation, destination, car);
    }
}

Fly::~Fly() {

}

