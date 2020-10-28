//
// Created by jo-anne on 2020/10/26.
//

#include "CateringEquipment.h"

using namespace log;

Tyres * CateringEquipment::unpack() {
    //Container::unpack();
}

CateringEquipment::CateringEquipment(std::list<std::string> insides) {
    if (insides.size() == 0) {
        contents.push_back("Lots and lots of stuff");
        return;
    }
    for (std::list<std::string>::iterator it = insides.begin(); it != insides.end(); ++it) {
        contents.push_back(*it);
    }
}

CateringEquipment::~CateringEquipment() = default;
