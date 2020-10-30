#include <specialists/Driver.h>
#include "Car.h"

using namespace eng;

Car::Car(int identification) {
    id = identification;
    driver = nullptr;
    damage = 0;
    components = nullptr;
}

int Car::getSpeed() const {
    if (components) {
        return 1;
    }
    return 0;
}

int Car::getHandling() const {
    if (components) {
        return 1;
    }
    return 0;
}

int Car::getDamage() const {
    return damage;
}

void Car::setDamage(int carDamage) {
    damage = carDamage;
}

ppl::Driver *Car::getDriver() {
    return driver;
}

void Car::removeDriver(ppl::Driver *driver) {
    driver = nullptr;
}

void Car::print() {
    // TODO - implement Car::print
    throw "Not yet implemented";
}

int Car::getDriverXP() {
    if (driver) {
        return driver->getXp();
    } else {
        return -1;
    }
}

bool Car::driverInCar() {
    return driver != nullptr;
}

int Car::getId() const {
    return this->id;
}

void Car::clone() {
    // TODO - implement Car::clone
    throw "Not yet implemented";
}
