//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include "BeingPackedState.h"
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

rce::Tyres * Container::unpack() {
    std::cout << "CONTAINER UNPACK BY printing out contents and returning the tyres in the container" << std::endl;
    return new rce::Tyres;

}

void Container::repack(rce::Tyres) {
    //add tyres to containers
    std::cout << "print out contents" << std::endl;
    //some other stuff

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


