#ifndef ENG_ENGTEAM_H
#define ENG_ENGTEAM_H

#include <componentDevelopment/Department.h>
#include "Car.h"
#include "../log/enums/RiskLevel.h"
#include "buildings/Garage.h"
#include "buildings/BlueprintStore.h"
#include "buildings/ComponentSimulator.h"
#include "buildings/WindTunnel.h"
#include "../log/Mediator.h"

namespace eng {
	class EngTeam {

	private:
		int improvementBudget = 0;
		Garage garage;
		BlueprintStore blueprint;
		WindTunnel windTunnel;
		ComponentSimulator simulator;
		log::Mediator* logisticsDep;
        Department* department[5];
        Risk* innovation;

	public:
		void hireEmployees(int budget);

		void registerForSeason(log::Mediator* logisticsDep);

		int buildCar(int budget, log::RiskLevel riskLevel);

		void carArrivesAtFactory(Car* car);

		void fixCar(int id);

		void improveCar(int id);

		Car* checkCarOutOfFactory(int id);

		void setRiskLevel(Risk* riskLevel);
	};
}

#endif
