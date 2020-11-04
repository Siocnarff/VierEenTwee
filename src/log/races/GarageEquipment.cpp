//
// Created by jo-anne on 2020/10/26.
//

#include <Doc.h>
#include "GarageEquipment.h"

using namespace lg;

/**
 * @author Marike
 * //TODO: create int parameter constructor
 */
GarageEquipment::GarageEquipment() {
    contents.emplace_back("Spare Tyres");
    contents.emplace_back("Oil can");
    contents.emplace_back("Elbow Grease");
    contents.emplace_back("Nuts and bolts");
    contents.emplace_back("A spanner");
}

GarageEquipment::GarageEquipment(std::list <std::string> insides) {
    if (insides.empty()) {
        contents.emplace_back("Lots and lots of stuff");
        return;
    }
    for (std::list<std::string>::iterator it = insides.begin(); it != insides.end(); ++it) {
        contents.push_back(*it);
    }
}

GarageEquipment::~GarageEquipment() = default;

void GarageEquipment::print() {
    pr::Doc::detail("Garage equipment:\n");
    for (std::list<std::string>::iterator it = contents.begin(); it != contents.end(); ++it) {
        pr::Doc::detail("   ");
        pr::Doc::detail(*it);
        pr::Doc::detail("\n");
    }
    pr::Doc::detail("\n");
}