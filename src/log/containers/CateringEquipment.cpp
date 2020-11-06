//
// Created by jo-anne on 2020/10/26.
//

#include <Doc.h>
#include "CateringEquipment.h"

using namespace lg;

/**
 * @author Marike
 */
CateringEquipment::CateringEquipment() {
    contents.emplace_back("Water Bottles");
    contents.emplace_back("Salty cracks");
    contents.emplace_back("Towels");
    contents.emplace_back("Batteries");
    contents.emplace_back("A torch");
}

CateringEquipment::CateringEquipment(int budget) {
    int arr = 4;

    std::string poorArr[] = {"Benches", "Water bottles", "Salty Cracks", "Gazebo"};
    std::string aveArr[] =  {"Camping chairs", "Energy drinks", "Nutri bars", "Tent"};
    std::string richArr[] = {"Hospitality Sofas - Inflatable", "Champagne", "Caviar", "Gala Performance Dual Pit Walling"};

    if (budget < 51) {
        for (int x = 0; x < arr; x++) {
            contents.push_back(poorArr[x]);
        }
    }
    else if (budget < 76) {
        for (int x = 0; x < arr; x++) {
            contents.push_back(aveArr[x]);
        }
    }
    else {
        for (int x = 0; x < arr; x++) {
            contents.push_back(richArr[x]);
        }
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
}