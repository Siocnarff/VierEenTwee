//
// Coordinators
// Josua Botha
// Gianni Volpi
//


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

EngTeam::EngTeam() {
    department[3] = new BodyDep();
    department[4] = new MicroTimeTravelDep(department[3]);
    department[2] = new ElectricDepartment(department[4]);
    department[1] = new EngineDep(department[2]);
    department[0] = new ChassisDep(department[1]);
}

EngTeam::~EngTeam() {
    for (auto & dep : department) {
        delete dep;
    }
}

void EngTeam::hireEmployees(int budget) {
    pr::Doc::midInfo("      --Engineering team hires new employees\n");
    pr::Doc::midInfo("\n");
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
    if (budget < 40) {
        humanResources = new ppl::KidnapStudent();
    } else if (budget < 70) {
        humanResources = new ppl::HireAmateur();
    } else {
        humanResources = new ppl::HireProfessional();
    }
    // Hire for all departments if hirelings sufficiently skilled (implied by budget >= 50)
    time_t t = time(nullptr);
    int time = (int) t;
    srand(time);

    for (int i = 0; i < 1 + int(budget / 20); ++i) {
        if (budget >= 70) {
            department[4]->addSpecialist(humanResources->hire(secretJobs[rand() % 5]));
        }
        department[3]->addSpecialist(humanResources->hire(bodyJobs[rand() % 5]));
        department[2]->addSpecialist(humanResources->hire(electricalJobs[rand() % 5]));
        department[1]->addSpecialist(humanResources->hire(engineJobs[rand() % 5]));
        department[0]->addSpecialist(humanResources->hire(chassisJobs[rand() % 5]));
    }
    delete humanResources;
}

void EngTeam::registerForSeason(lg::Mediator *mediator) {
    logisticsDept = mediator;
}

int EngTeam::generateId() {
    static int nextNewId = 0;
    return nextNewId++;
}

int EngTeam::buildCar(int budget) {
    int id = generateId();
    Car *prototype = garage.getPrototype();
    cashUpDeps(prototype ? budget : budget - 50);
    Car *car;
    if (prototype) {
        car = prototype->clone(id);
    } else {
        car = new Car(id);
        department[0]->build(car);
    }
	windTunnel.testCar(car);
    garage.storeCar(car);
    car->print();
    int transparency = pr::Doc::transparency;
    for (int i = 0; i < 10; ++i) {
        improveCar(id, true);
        pr::Doc::transparency = -1;
    }
    pr::Doc::transparency = transparency;
    pr::Doc::midInfo("\n");
    return id;
}

void EngTeam::cashUpDeps(int cash) {
    if (cash > 0) {
        for (auto &dep : department) {
            dep->topUpBudget(cash);
        }
    }
}


void EngTeam::setRiskLevel(lg::RiskLevel riskLevel) {
    for (auto &dep : department) {
        dep->setRiskLevel(riskLevel);
    }
}

void EngTeam::carArrivesAtFactory(Car *car) {
    garage.storeCar(car);
}

void EngTeam::fixCar(int id) {
    if (department[0]) {
        Car *car = garage.retrieveCar(id);
        department[0]->fix(car);
        garage.storeCar(car);
    }
}

void EngTeam::improveCar(int id, bool usingWindTunnel) {
	Car* car = garage.retrieveCar(id);
    if (usingWindTunnel && windTunnel.sufficientTickets()) {
    	windTunnel.testCar(car);
    } else {
		simulator.testComponents(car);
    }
    pr::Doc::midInfo("  ~Improve components of car, storing blueprints for use in later season~\n");
    for (int num = 0; num < 5; num++) {
		Component* component = car->components[num];
		if (component) {
			int currentQuality = component->getQualityLabel();
			blueprintStore.setBlueprint(component->createBlueprint());
			department[num]->update(component);
			simulator.testComponent(component);
			int changedQuality = component->getQualityLabel();
			if (currentQuality > changedQuality) {
				component->rebuildComponent(blueprintStore.getBlueprint());
			}
		}
	}
    garage.storeCar(car);
}

Car *EngTeam::checkCarOutOfFactory(int id) {
	return garage.retrieveCar(id);
}

void EngTeam::resetTickets() {
    windTunnel.resetTickets();
}
