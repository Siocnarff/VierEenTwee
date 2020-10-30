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

void Department::build(Car *car) {
    // TODO - implement Department::build
    throw "Not yet implemented";
}

void Department::fix(Car *car) {
    // TODO - implement Department::fix
    throw "Not yet implemented";
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

void Department::topUpBudget(int cash) {
    budget += cash;
}
