#include <specialists/Driver.h>
#include <iostream>
#include "Car.h"

using namespace eng;

eng::Car::Car(int identification) {
    id = identification;
    for (int i = 0; i < 5; ++i) {
        components[i] = nullptr;
    }
}

Car::Car(Car *car) {
    id = car->id;
    driver = car->driver;
    for (int i = 0; i < 5; ++i) {
    	if (car->components[i]) {
			components[i] = car->components[i]->clone();
		} else {
    		components[i] = nullptr;
    	}
    }
}

Car::~Car() {
//    std::cout << id << std::endl;
    for (auto & component : components) {
        delete component;
        component = nullptr;
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
		handling += components[0]->quality / 3;
	}
	if (components[2]) {
		handling += components[2]->quality / 3;
	}
	if (components[3]) {
		handling += components[3]->quality / 3;
	}
	return handling;
}

int Car::getDamage() const {
    int damage = 0;
    for (auto component : components) {
        if (component) {
            damage += component->damage;
        }
    }
    return damage/5;
}

void Car::setDamage(int carDamage) {
    carDamage = carDamage*5;
    for (auto & component : components) {
        if(component) {
            component->damage = 0;
        }
    }
    while (carDamage > 0) {
        for (auto & component : components) {
            if (component) {
                int d = rand() % 101;
                if(carDamage < d) {
                    d = carDamage;
                }
                if (component->damage + d <= 100) {
                    carDamage -= d;
                    component->damage += d;
                }
            }
        }
    }
}

ppl::Driver *Car::getDriver() {
    return driver;
}

void Car::removeDriver(ppl::Driver *driver) {
    driver = nullptr;
}

void Car::print() {
    pr::Doc::detail("CAR INFO: id=");
    pr::Doc::detail(std::to_string(id));
    pr::Doc::detail(" Driver=" + (driver ? driver->getName() : "None") + "\n");
    pr::Doc::detail("  Detail:");
    pr::Doc::detail(" Damage=" + std::to_string(getDamage()));
    pr::Doc::detail(" Speed=" + std::to_string(getSpeed()));
    pr::Doc::detail(" Handling=" + std::to_string(getHandling()) + "\n");
    pr::Doc::detail("    Components:\n");
    for (auto &component : components) {
        if (component) {
            component->print();
        }
    }
    pr::Doc::detail("\n------------------------------\n\n");
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
