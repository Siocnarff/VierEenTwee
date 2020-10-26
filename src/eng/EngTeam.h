#ifndef ENG_ENGTEAM_H
#define ENG_ENGTEAM_H

#include "../dev/Risk.h"
#include "Car.h"
#include "../log/RiskLevel.h"
#include "Garage.h"
#include "BlueprintStore.h"
#include "ComponentSimulator.h"
#include "WindTunnel.h"
#include "../dev/Department.h"
#include "../log/Mediator.h"

namespace eng {
	class EngTeam {

	private:
		int improvementBudget;
		Garage garage;
		BlueprintStore blueprint;
		WindTunnel windTunnel;
		ComponentSimulator simulator;
		log::Mediator* logisticsDep;
        Department** department;

	public:
		void hireEmployees(int budget);

		void registerForSeason(log::Mediator* logisticsDep);

		int buildCar(int budget, log::RiskLevel riskLevel);

		void carArrivesAtFactory(Car* car);

		void fixCar(int id);

		void improveCar(int id);

		Car* checkCarOutOfFactory(int id);

		void setRiskLevel(Risk riskLevel);
	};
}

#endif
