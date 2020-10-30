//
// Created by jo-anne on 2020/10/26.
//

#include "GarageEquipment.h"

using namespace log;

GarageEquipment::GarageEquipment() {}

GarageEquipment::GarageEquipment(std::list <std::string> insides) {
    if (insides.size() == 0) {
        contents.push_back("Lots and lots of stuff");
        return;
    }
    for (std::list<std::string>::iterator it = insides.begin(); it != insides.end(); ++it) {
        contents.push_back(*it);
    }
}

rce::Tyres * GarageEquipment::unpack() {
    for (std::list<std::string>::iterator it = contents.begin(); it != contents.end(); ++it) {
        std::cout << "-" << (*it) << std::endl;
    }
    return nullptr;
}

GarageEquipment::~GarageEquipment() = default;