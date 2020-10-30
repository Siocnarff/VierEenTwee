#include "Garage.h"

using namespace eng;

void Garage::storeCar(Car *c) {
    for (int i = 0; i < 20; ++i) {
        if (lookup[i] == -1) {
            car[i] = c;
            lookup[i] = c->getId();
        }
    }
    throw "Garage is full!";
}

Car *Garage::retrieveCar(int id) {
    for (int i = 0; i < 20; ++i) {
        if (lookup[i] == id) {
            lookup[i] = -1;
            return car[i];
        }
    }
    return nullptr;
}

Car *Garage::getPrototype() {
    for (int i = 0; i < 20; ++i) {
        if (lookup[i] != -1) {
            return car[i];
        }
    }
    return nullptr;
}
