//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include <iostream>
using namespace std;

void Container::changeState() {
    containerCurrentState->changeState(this);
}

void Container::setState(ContainerState *state) {
    delete this->containerCurrentState;
    this->containerCurrentState = state;
}

string Container::getState() {
    return containerCurrentState->getState();
}

void Container::takeStock() {
    cout << "CONTAINER STOCK TAKE" << endl;

}

void BeingPacked::changeState(Container *container) {
    container->setState(new InShipping());

}

string BeingPacked::getState() {
    return "Being Packed" ;
}

void InShipping::changeState(Container *container) {
    container->setState(new ArrivedAtDestination());
}

string InShipping::getState() {
    return "In Shipping" ;
}


void ArrivedAtDestination::changeState(Container *container) {
    container->setState(new BeingPacked());

}

string ArrivedAtDestination::getState() {
    return "Arrived at Destination";
}

void Box::addElement(Container *c) {
    elements.push_back(c);

}

Container *Box::removeElement() {
    elements.pop_back();
}

void Box::takeStock() {
    Container::takeStock();
    cout << "\nBox contains: " <<endl;
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        (*it)->takeStock();
    }
}

Box::~Box() {
    for (std::list<Container*>::iterator it = elements.begin(); it != elements.end(); ++it) {
        delete *it;
    }
}

GarageEquipment::GarageEquipment(list<string> insides) {
    if (insides.size() == 0) {
        contents.push_back("Lots and lots of stuff");
        return;
    }
    for (std::list<string>::iterator it = insides.begin(); it != insides.end(); ++it) {
        contents.push_back(*it);
    }
}

void GarageEquipment::takeStock() {
    for (std::list<string>::iterator it = contents.begin(); it != contents.end(); ++it) {
        cout << "-" << (*it) << endl;
    }
}

GarageEquipment::~GarageEquipment() {

}


