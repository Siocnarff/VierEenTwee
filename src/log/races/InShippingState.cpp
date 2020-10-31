//
// Created by jo-anne on 2020/10/26.
//

#include "InShippingState.h"
#include "ArrivedState.h"

using namespace lg;

void InShippingState::nextState(Container *container) {
    container->setState(new ArrivedState());
}

std::string InShippingState::getState() {
    return "In Shipping" ;
}

InShippingState::~InShippingState() = default;