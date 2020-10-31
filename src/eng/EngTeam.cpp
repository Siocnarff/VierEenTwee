#include <HumanResources.h>
#include <factories/KidnapStudent.h>
#include <factories/HireAmateur.h>
#include <factories/HireProfessional.h>
#include <componentDevelopment/BodyDep.h>
#include <componentDevelopment/MicroTimeTravelDep.h>
#include <componentDevelopment/ElectricDepartment.h>
#include <componentDevelopment/EngineDep.h>
#include <componentDevelopment/ChassisDep.h>
#include "EngTeam.h"
#include <chrono>

using namespace eng;

void EngTeam::hireEmployees(int budget) {
    print("Engineering team is hiring new employees...");
    std::string secretJobs[6] = {
            "Neolithic Researcher",
            "Plutonium Handler",
            "Dark Matter Prof",
            "Basically Marty",
            "Doc",
            "Quantum Physicist"
    };
    std::string bodyJobs[6] = {
            "Carbon Fiber Expert",
            "Carbon Fiber Health Expert",
            "Aerodynamic Bettering Guy",
            "Makes the car look sexy",
            "Painter",
            "Impacts Expert"
    };
    std::string electricalJobs[6] = {
            "High Voltage Electrician",
            "Neaten Wires",
            "Computer Scientist",
            "Electrical Engineer",
            "Computer Engineer",
            "Micro Sensors Expert"
    };
    std::string chassisJobs[6] = {
            "Spring Rebound Doctor",
            "Mechanical Engineer",
            "Computer Analyst",
            "Rotational Delay Calculator",
            "Suspension Mechanic",
            "Factotum"
    };
    std::string engineJobs[6] = {
            "Mechanical Engineer",
            "Makes Things Explode",
            "Fuel Facilitator",
            "CNC Operator",
            "Metallurgical Engineer",
            "CAD Guy"
    };
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
    department[2] = new ElectricDepartment(department[3]);
    department[1] = new EngineDep(department[2]);
    department[0] = new ChassisDep(department[1]);
    // Hire for all departments if hirelings sufficiently skilled (implied by budget >= 50)
    time_t t = time(nullptr);
    int time = (int) t;
    srand(time);
    for (int i = 0; i < 1 + int(budget / 20); ++i) {
        if (budget >= 50) {
            department[3]->addSpecialist(humanResources->hire(secretJobs[rand() % 5]), transparent);
        }
        department[4]->addSpecialist(humanResources->hire(bodyJobs[rand() % 5]), transparent);
        department[2]->addSpecialist(humanResources->hire(electricalJobs[rand() % 5]), transparent);
        department[1]->addSpecialist(humanResources->hire(engineJobs[rand() % 5]), transparent);
        department[0]->addSpecialist(humanResources->hire(chassisJobs[rand() % 5]), transparent);
    }
}

int EngTeam::buildCar(int budget) {
    cashUpDeps(budget);
    int id = carIdGenerator++;
    department[0]->build(new Car(id));
    return id;
}

void EngTeam::cashUpDeps(int cash) {
    for (auto &dep : department) {
        dep->topUpBudget(cash);
    }
}


void EngTeam::setRiskLevel(log::RiskLevel riskLevel) {
    for (auto &dep : department) {
        dep->setRiskLevel(riskLevel);
    }
}

void EngTeam::carArrivesAtFactory(Car *car) {
    garage.storeCar(car);
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

void EngTeam::toggleTransparency() {
    transparent = !transparent;
}

void EngTeam::print(const std::string &message) const {
    if (transparent) {
        std::cout << message << std::endl;
    }
}

void EngTeam::registerForSeason(log::Mediator* mediator) {
    logistcsDep = mediator;
}
