//
// Created by jo-anne on 2020/10/22.
//

#include "Box.h"
using namespace log;

void Box::addElement(Container *c) {
    elements.push_back(c);
}

Container *Box::removeElement() {
    elements.pop_back();
}

void Box::takeStock() {
    Container::takeStock();
    std::cout << "\nBox contains: " << std::endl;
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        (*it)->takeStock();
    }
}

Box::~Box() {
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        delete *it;
    }
}


