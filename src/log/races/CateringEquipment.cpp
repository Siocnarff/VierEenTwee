//
// Created by jo-anne on 2020/10/26.
//

#include "CateringEquipment.h"

using namespace log;

rce::Tyres * CateringEquipment::unpack() {
    //Container::unpack();
    //moet verander word -- Okay, so die functionality moet verander . . . ?? Ons moet wanneer dit unpack, moet ons deur al die unpack() funksies
    //run, en al die dinge noem wat ge-unpack word. Hoe werk ons pack? Dit is wanneer die container ge-instantiate word.
    return new rce::Tyres;
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
