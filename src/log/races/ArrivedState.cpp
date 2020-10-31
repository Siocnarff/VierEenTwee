//
// Created by jo-anne on 2020/10/23.
//

#include "ArrivedState.h"
#include "BeingPackedState.h"

using namespace lg;

void ArrivedState::nextState(Container *container) {
    container->setState(new BeingPackedState());

}

std::string ArrivedState::getState() {
    return "Arrived at Destination";
}

ArrivedState::~ArrivedState() = default;

