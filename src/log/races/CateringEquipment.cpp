//
// Created by jo-anne on 2020/10/26.
//

#include <Doc.h>
#include "CateringEquipment.h"

using namespace lg;

/**
 * @author Marike
 * TODO: create constructor with int parameter
 */
CateringEquipment::CateringEquipment() {
    contents.emplace_back("Water Bottles");
    contents.emplace_back("Salty cracks");
    contents.emplace_back("Towels");
    contents.emplace_back("Batteries");
    contents.emplace_back("A torch");
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

void CateringEquipment::print() {
    pr::Doc::detail("Catering Equipment:\n");
    for (std::list<std::string>::iterator it = contents.begin(); it != contents.end(); ++it) {
        pr::Doc::detail("   ");
        pr::Doc::detail(*it);
        pr::Doc::detail("\n");
    }
    pr::Doc::detail("\n");
}