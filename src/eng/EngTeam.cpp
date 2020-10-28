#include <HumanResources.h>
#include <factories/KidnapStudent.h>
#include <factories/HireAmateur.h>
#include <factories/HireProfessional.h>
#include <componentDevelopment/BodyDep.h>
#include <componentDevelopment/MicroTimeTravelDep.h>
#include <componentDevelopment/ElectronicDep.h>
#include <componentDevelopment/EngineDep.h>
#include <componentDevelopment/ChassisDep.h>
#include "EngTeam.h"

using namespace eng;

void EngTeam::hireEmployees(int budget) {
    ppl::HumanResources *humanResources;
    if (budget < 20) {
        humanResources = new ppl::KidnapStudent();
    } else if (budget < 50) {
        humanResources = new ppl::HireAmateur();
    } else {
        humanResources = new ppl::HireProfessional();
    }
    department[4] = new BodyDep();
    department[3] = new MicroTimeTravelDep(department[4]);
    department[2] = new ElectronicDep(department[3]);
    department[1] = new EngineDep(department[2]);
    department[0] = new ChassisDep(department[1]);
    // Hire for all departments if hirelings sufficiently skilled (implied by budget >= 50)
    for (int i = 0; i < 1 + budget; ++i) {
        if (budget >= 50) {
            department[3]->addSpecialist(humanResources->hire(""));
        }
        department[4]->addSpecialist(humanResources->hire(""));
        department[2]->addSpecialist(humanResources->hire(""));
        department[1]->addSpecialist(humanResources->hire(""));
        department[0]->addSpecialist(humanResources->hire(""));
    }
}

void EngTeam::registerForSeason(log::Mediator *logisticsDep) {
    // TODO - implement EngTeam::registerForSeason
    throw "Not yet implemented";
}

int EngTeam::buildCar(int budget, log::RiskLevel riskLevel) {
    // TODO - implement EngTeam::buildCar
    throw "Not yet implemented";
}

void EngTeam::carArrivesAtFactory(Car *car) {
    // TODO - implement EngTeam::carArrivesAtFactory
    throw "Not yet implemented";
}

void EngTeam::fixCar(int id) {
    // TODO - implement EngTeam::fixCar
    throw "Not yet implemented";
}

void EngTeam::improveCar(int id) {
    // TODO - implement EngTeam::improveCar
    throw "Not yet implemented";
}

Car *EngTeam::checkCarOutOfFactory(int id) {
    // TODO - implement EngTeam::checkCarOutOfFactory
    throw "Not yet implemented";
}

void EngTeam::setRiskLevel(Risk *riskLevel) {
    innovation = riskLevel;
}