//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include <iostream>
#include <Doc.h>

using namespace lg;

Container::Container() {
}

Container::~Container() {

}

void Container::addElement(Container * newContainer) {
    pr::Doc::detail("Pack box into main container");
}

void Container::print() {
    pr::Doc::detail("The container is currently empty");
}

