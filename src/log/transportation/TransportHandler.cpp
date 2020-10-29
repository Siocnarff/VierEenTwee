//
// Created by jo on 2020/10/17.
//

#include "TransportHandler.h"
using namespace log;

void TransportHandler::hireEmployees(int budget) {

}

void TransportHandler::addAMethod(TransportHandler *transport) {
    if (nextTransportationMethod) {
        //notify?
        //nextTransportationMethod->addAMethod(transport);
    }
    else {
        nextTransportationMethod = transport;
    }
}

void TransportHandler::transport(Race *fromLocation, Race *destination, eng::Car *car) {
    if (nextTransportationMethod) {
        nextTransportationMethod->transport(fromLocation, destination, car);
    } else {
        cout << "Cannot handle request" << endl;
    }
}

TransportHandler::~TransportHandler() {
    delete nextTransportationMethod;
}
