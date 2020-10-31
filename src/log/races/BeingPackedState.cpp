//
// Created by jo-anne on 2020/10/26.
//

#include "BeingPackedState.h"
#include "InShippingState.h"

using namespace lg;

void BeingPackedState::nextState(Container *container) {
    container->setState(new InShippingState());
}

std::string BeingPackedState::getState() {
    return "Being Packed" ;
}

BeingPackedState::~BeingPackedState() = default;
