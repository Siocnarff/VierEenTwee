#include <iostream>
#include "Department.h"
#include "Safe.h"
#include "Moderate.h"
#include "Aggressive.h"

using namespace eng;

void Department::setRiskLevel(log::RiskLevel level) {
    if (level == log::Safe) {
        riskLevel = new Safe();
    } else if (level == log::Moderate) {
        riskLevel = new Moderate();
    } else if (level == log::Aggressive) {
        riskLevel = new Aggressive();
    }
}

Department::Department(Department *next) {
    riskLevel = new Moderate();
    nextDepartment = next;
}

void Department::addSpecialist(ppl::Person *specialist, bool printResults) {
    specialists.push_back(specialist);
    if (printResults) {
        std::cout << departmentName << " hired a new specialist:\n";
        specialist->printResume();
        std::cout << std::endl;
    }
}

void Department::fix(Car *car, bool transparent) {
	if (nextDepartment) {
		nextDepartment->fix(car, transparent);
	} else {
		if (transparent) {
			std::cout << "There are no more departments, the car has been completely fixed and stored in garage." << std::endl;
		}
	}
}

void Department::topUpBudget(int cash) {
    budget += cash;
}

int Department::fixComponent(Car *car, int id) {
	int damage = car->components[id]->damage;
	car->components[id]->damage = 0;
	return damage;
}

bool Department::haveSpecialists() {
	return !specialists.empty();
}

void Department::build(Car *car) {
    if (nextDepartment) {
        nextDepartment->build(car);
    } else {
        std::cout << "Car has been build" << std::endl;
    }
}

void Department::buildComponentIntoCar(Car *car, Component *comp) {
    car->components[comp->getId()] = comp;
}
