//
// Created by jo-anne on 2020/10/23.
//

#include "SubStates.h"

void BeingPacked::nextState(Container *container) {
    container->setState(new InShipping());
}

string BeingPacked::getState() {
    return "Being Packed" ;
}

BeingPacked::~BeingPacked() = default;

void InShipping::nextState(Container *container) {
    container->setState(new ArrivedAtDestination());
}

string InShipping::getState() {
    return "In Shipping" ;
}

InShipping::~InShipping() = default;


void ArrivedAtDestination::nextState(Container *container) {
    container->setState(new BeingPacked());

}

string ArrivedAtDestination::getState() {
    return "Arrived at Destination";
}

ArrivedAtDestination::~ArrivedAtDestination() = default;

