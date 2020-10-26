//
// Created by jo-anne on 2020/10/22.
//
#include <iostream>
#include "ContainerParts.h"

void CateringEquipment::takeStock() {
    //Container::takeStock();
}

CateringEquipment::~CateringEquipment() = default;

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

GarageEquipment::~GarageEquipment() = default;