#include "Garage.h"

using namespace eng;

void Garage::storeCar(Car *c) {
	pr::Doc::detail("\n     [_] Storing car in garage. [_]\n");
    pr::Doc::detail("\t\tCar has id: " + std::to_string(c->getId()) + "\n");
    for (int i = 0; i < cars.size(); i++) {
        if (!cars[i] || cars[i] == c) {
            cars[i] = c;
			pr::Doc::detail("\t\tAnd is stored at position " + std::to_string(i) + "\n");
            pr::Doc::detail("     ------------------------------\n\n");
            return;
        }
    }
    cars.push_back(c);
    pr::Doc::detail("\t\tAnd is stored at position " + std::to_string(cars.size() - 1) + "\n");
    pr::Doc::detail("     ------------------------------\n\n");
}

Car *Garage::retrieveCar(int id) {
    for (auto & car : cars) {
        if (car && car->getId() == id) {
            Car *target = car;
            car = nullptr;
            return target;
        }
    }
    return nullptr;
}

Car *Garage::getPrototype() {
    int bestPerformance = -1;
    int idOfBest = -1;
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i]) {
            int performance = cars[i]->getSpeed() + cars[i]->getHandling();
            if (performance > bestPerformance) {
                bestPerformance = performance;
                idOfBest = i;
            }
        }
    }
    if (idOfBest != -1) {
        return cars[idOfBest];
    }
    return nullptr;
}

//TODO: Put Garage destructor back. Commented out for reasons of misbehaving code
Garage::~Garage() {
    for (auto & car : cars)
    {
        delete car;
        car = nullptr;
    }
}
