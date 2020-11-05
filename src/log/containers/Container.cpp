//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include <iostream>
using namespace lg;

Container::Container() {
}

Container::~Container() {

}

void Container::addElement(Container * newContainer) {
    std::cout << "Pack box into main container" << std::endl;
}

void Container::print() {
    std::cout << "The container is currently empty" << std::endl;
}

