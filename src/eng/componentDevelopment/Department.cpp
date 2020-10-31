#include <iostream>
#include <pr/Doc.h>
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

void Department::addSpecialist(ppl::Person *specialist) {
    specialists.push_back(specialist);
    pr::Doc::summary(departmentName + " hired a new specialist\n");
    pr::Doc::detail(specialist->getResume());
}

void Department::fix(Car *car) {
    if (nextDepartment) {
        nextDepartment->fix(car);
    } else {
        pr::Doc::summary("There are no more departments, the car has been completely fixed and stored in garage.");
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
        pr::Doc::summary("Car " + std::to_string(car->getId()) + " has been build");
    }
}

void Department::buildComponentIntoCar(Car *car, Component *comp) {
    car->components[comp->getId()] = comp;
}

int Department::specialistsDesignComponent() {
    if (!haveSpecialists()) {
        return 0;
    }
    int best = -1;
    int teamSize = specialists.size();
    int totalSkill = 0;
    for (ppl::Person *specialist: specialists) {
        if (specialist->getSkillLevel() > best) {
            best = specialist->getSkillLevel();
        }
        totalSkill += specialist->getSkillLevel();
    }
    double average = double(totalSkill) / double(teamSize);
    return (int(average * 0.2 + double(best) * 0.8) + riskLevel->trySomethingNew()) % 100;
}
