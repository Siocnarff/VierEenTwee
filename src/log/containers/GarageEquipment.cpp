//
// Created by jo-anne on 2020/10/26.
//

#include <Doc.h>
#include "GarageEquipment.h"

using namespace lg;

/**
 * @author Marike
 * //todolist: create int parameter constructor
 */
GarageEquipment::GarageEquipment() {
    contents.emplace_back("Spare Tyres");
    contents.emplace_back("Oil can");
    contents.emplace_back("Elbow Grease");
    contents.emplace_back("Nuts and bolts");
    contents.emplace_back("A spanner");
}

GarageEquipment::GarageEquipment(int budget) {
    int arr = 5;
   std::string poorArr[5] = {"Spanners", "Extra helmet", "Elbow Grease", "Nuts and bolts", "Vehicle Skates"};
   std::string aveArr[5] =  {"Wheel guns", "Custom paint helmet", "Ratchet", "Dive bottle compressor", "Air Lifts"};
   std::string richArr[5] = {"Easy roll rim cleaner", "Air bottle trolleys", "Tyre warmer tent", "Box with secret compartment for Plutonium Hammer", "Wheel Gun Service Kits"};

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

GarageEquipment::~GarageEquipment() = default;

void GarageEquipment::print() {
    pr::Doc::detail("\tGarage equipment:\n");
    for (std::list<std::string>::iterator it = contents.begin(); it != contents.end(); ++it) {
        pr::Doc::detail("   \t");
        pr::Doc::detail(*it);
        pr::Doc::detail("\n");
    }
    pr::Doc::detail("\n");
}