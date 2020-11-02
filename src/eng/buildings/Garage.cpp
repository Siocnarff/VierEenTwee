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
    int bestPerformance = -1;
    int idOfBest = -1;
    for (int i = 0; i < 20; ++i) {
        if (lookup[i] != -1) {
            int performance = car[i]->getSpeed() + car[i]->getHandling();
            if (performance > bestPerformance) {
                bestPerformance = performance;
                idOfBest = i;
            }
        }
    }
    if (idOfBest != -1) {
        return car[idOfBest];
    }
    return nullptr;
}

Garage::~Garage() {
    for (Car * c : car) {
        delete c;
        c = nullptr;
    }
}
