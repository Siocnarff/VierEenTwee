#include "Garage.h"

using namespace eng;

void Garage::storeCar(Car *c) {
	pr::Doc::summary("\n[_] Storing car in garage. [_]\n");
    for (int i = 0; i < 20; ++i) {
        if (lookup[i] == -1) {
            car[i] = c;
            lookup[i] = c->getId();
			pr::Doc::detail("Car has id: " + std::to_string(c->getId()));
			pr::Doc::detail("\nAnd is stored at position " + std::to_string(i) + "\n");
            break;
        }
    }
	pr::Doc::summary("--------------------------------------\n\n");
}

Car *Garage::retrieveCar(int id) {
    for (int i = 0; i < 20; ++i) {
        if (lookup[i] == id) {
            lookup[i] = -1;
            Car *target = car[i];
            car[i] = nullptr;
            return target;
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

Garage::Garage() {
    for (int i = 0; i < 20; ++i) {
        lookup[i] = -1;
        car[i] = nullptr;
    }
}
