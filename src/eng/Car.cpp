#include <specialists/Driver.h>
#include <iostream>
#include "Car.h"

using namespace eng;

eng::Car::Car(int identification) {
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
	int speed = 0;
	if (components[1]) {
		speed += components[1]->quality / 3;
	}
	if (components[3]) {
		speed += components[3]->quality / 3;
	}
	if (components[4]) {
		speed += components[4]->quality / 3;
	}
	return speed;
}

int Car::getHandling() const {
	int handling = 0;
	if (components[0]) {
		handling += components[1]->quality / 3;
	}
	if (components[2]) {
		handling += components[3]->quality / 3;
	}
	if (components[3]) {
		handling += components[4]->quality / 3;
	}
	return handling;
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
    pr::Doc::summary("CAR INFO: id=" + std::to_string(id));
    pr::Doc::summary(std::to_string(id));
    pr::Doc::summary(" Driver=" + (driver ? driver->getName() : "None") + "\n");
    pr::Doc::detail("  Detail:");
    pr::Doc::detail(" Damage=" + std::to_string(damage));
    pr::Doc::detail(" Speed=" + std::to_string(getSpeed()));
    pr::Doc::detail(" Handling=" + std::to_string(getHandling()) + "\n");
    pr::Doc::detail("    Components:\n");
    for (auto &component : components) {
        if (component) {
            component->print();
        }
    }
    pr::Doc::summary("----\n");
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

Car *Car::clone() {
    return new Car(this);
}

Car *Car::clone(int idOfNew) {
    Car *newCar = new Car(this);
    newCar->id = idOfNew;
    return newCar;
}
