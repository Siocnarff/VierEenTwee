#include <specialists/Driver.h>
#include <iostream>
#include "Car.h"

using namespace eng;

Car::Car(int identification) {
    id = identification;
}

Car::Car(Car *car) {
    id = car->id;
    driver = car->driver;
    damage = car->damage;
    for (int i = 0; i < 5; ++i) {
        components[i] = car->components[i]->clone();
    }
}

int Car::getSpeed() const {
    throw "not yet implemented";
}

int Car::getHandling() const {
    throw "not yet implemented";
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
    std::cout << "CAR STATS:\n"
              << "    id: " << id << std::endl
              << "    Driver: " << (driver ? driver->getName() : "No Driver") << std::endl
              << "    Damage: " << damage << std::endl
              << "    Components:" << std::endl;
    for (auto &component : components) {
        if (component) {
            component->print();
        }
    }
    std::cout << "    Speed: " << getSpeed() << std::endl
              << "    Handling: " << getHandling() << std::endl
              << "----\n";
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

Car * Car::clone() {
    return new Car(this);
}
