//
// Created by jo-anne on 2020/10/22.
//

#include "Box.h"
using namespace lg;

Box::Box() {}

void Box::addElement(Container *c) {
    elements.push_back(c);
}

Box::~Box() {
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        delete *it;
    }
}

void Box::print() {
    if (!elements.empty()) {
        for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
            (*it)->print();
        }
    }
    else {
        std::cout << "Empty" << std::endl;
    }
}