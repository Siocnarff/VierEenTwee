//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include "ArrivedState.h"
#include <iostream>
using namespace log;

Container::Container() {
    this->containerCurrentState = new BeingPackedState();
}

Container::~Container() {
    delete containerCurrentState;
}

void Container::setState(ContainerState *state) {
    delete this->containerCurrentState;
    this->containerCurrentState = state;
}

std::string Container::getState() {
    return containerCurrentState->getState();
}

void Container::takeStock() {
    std::cout << "CONTAINER STOCK TAKE" << std::endl;

}

void Container::addElement(Container *) {
    //remains to be implemented
}

Container *Container::removeElement() {
    //remains to be implemented
    return nullptr;
}

void Container::advanceState() {
    containerCurrentState->nextState(this);
}


