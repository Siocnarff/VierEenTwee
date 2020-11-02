#include <iostream>
#include <pr/Doc.h>
#include "Department.h"
#include "Safe.h"
#include "Moderate.h"
#include "Aggressive.h"

using namespace eng;

void Department::setRiskLevel(lg::RiskLevel level) {
    if (level == lg::Safe) {
        riskLevel = new Safe();
    } else if (level == lg::Moderate) {
        riskLevel = new Moderate();
    } else if (level == lg::Aggressive) {
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
        pr::Doc::summary("There are no more departments, the car has been fixed and stored in garage.");
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
        pr::Doc::summary("Car " + std::to_string(car->getId()) + " has been built.");
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
    double result = int(average * 0.2 + double(best) * 0.4 + riskLevel->trySomethingNew() * 0.4);
    if (result > 100) {
    	result = 100;
    } else if (result < 0) {
		result = 0;
    }
    return (int)result;
}

void Department::specialistsImproveComponent(Component* component) {
	if (!haveSpecialists()){
		return;
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
	double result = int(average * 0.1 + best * 0.2 + riskLevel->trySomethingNew() * 0.7);
	double percentage = ((100-component->quality)/100.0 > 0.05)? 0.05 : (100-component->quality)/200.0;
	component->quality = (int)(result * percentage);
}