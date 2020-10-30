#include "Garage.h"

using namespace eng;

void Garage::storeCar(Car *c) {
    unsigned long storageLocation = lookup.size();
    if(storageLocation < 20) {
        car[storageLocation] = c;
        lookup.push_back(c->getId());
    } else {
        throw "Garage is full!";
    }
}

Car *Garage::retrieveCar(int id) {
    for (int i = 0; i < lookup.size(); ++i) {
        if (lookup[i] == id) {
            return car[i];
        }
    }
    return nullptr;
}

Car *Garage::getPrototype() {
    if (lookup.empty()) {
        return nullptr;
    }
    return car[lookup[0]];
}
