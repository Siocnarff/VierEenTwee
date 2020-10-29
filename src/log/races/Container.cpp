//
// Created by jo on 2020/10/17.
//

#include "Container.h"
#include <iostream>
using namespace log;

Container::Container() {
}

Container::~Container() {

}

rce::Tyres * Container::unpack() {
    std::cout << "CONTAINER UNPACK BY printing out contents and returning the tyres in the container" << std::endl;
    return new rce::Tyres;

}

void Container::pack(rce::Tyres, std::list<std::string> garageList, std::list<std::string> cateringList) {
    //add tyres to containers
    //Instantiate GarageEquipment and CateringEquipment (according to riskLevel/budget?)
    //Link container to box containing boxes containing CateringEquip and GarageEquip (one box to both?)




    std::cout << "print out contents" << std::endl;
    //some other stuff

}

void Container::addElement(Container *) {
    //remains to be implemented
}

