//
// Created by jo on 2020/10/17.
//

#include "TransportHandler.h"
using namespace lg;

void TransportHandler::hireEmployees(int budget) {

}

void TransportHandler::addAMethod(TransportHandler *transport) {
    if (nextTransportationMethod) {
        //notify?
        nextTransportationMethod->addAMethod(transport);
    }
    else {
        nextTransportationMethod = transport;
    }
}


TransportHandler::~TransportHandler() {
    if (nextTransportationMethod) {
        delete nextTransportationMethod;
    }

}

void TransportHandler::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (nextTransportationMethod) {
        nextTransportationMethod->transport(fromLocation, destination, car);
    } else {
        pr::Doc::detail("Cannot handle request");
    }
}
