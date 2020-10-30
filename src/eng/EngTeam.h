#ifndef ENG_ENGTEAM_H
#define ENG_ENGTEAM_H

#include <componentDevelopment/Department.h>
#include <Colleague.h>
#include "Car.h"
#include "../log/enums/RiskLevel.h"
#include "buildings/Garage.h"
#include "buildings/BlueprintStore.h"
#include "buildings/ComponentSimulator.h"
#include "buildings/WindTunnel.h"
#include "../log/Mediator.h"

namespace eng {
    class EngTeam : public log::Colleague {

    private:
        bool transparent = false;
        int carIdGenerator = 0;
        Garage garage;
        BlueprintStore blueprint;
        WindTunnel windTunnel;
        ComponentSimulator simulator;
        log::Mediator *logisticsDep;
        Department *department[5];
        Risk *innovation;

        void briefDepartments(int cash, log::RiskLevel riskLevel);

    public:
        explicit EngTeam(log::Mediator* mediator);

        void hireEmployees(int budget) override;

        int buildCar(int budget, log::RiskLevel riskLevel);

        void carArrivesAtFactory(Car *car);

        void fixCar(int id);

        void improveCar(int id);

		void setRiskLevel(Risk* riskLevel);

        Car *checkCarOutOfFactory(int id);

        void toggleTransparency();
    };
}

#endif