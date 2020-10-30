//
// Created by jo-anne on 2020/10/22.
//

#include "races/Tyres.h"
#include "Box.h"
using namespace log;

Box::Box() {}

void Box::addElement(Container *c) {
    elements.push_back(c);
}


rce::Tyres * Box::unpack() {
    Container::unpack();
    std::cout << "\nBox contains: " << std::endl;
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        (*it)->unpack();
    }
    //Moet verander word en reg-geimplementeer word
    return nullptr;
}

Box::~Box() {
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        delete *it;
    }
}


