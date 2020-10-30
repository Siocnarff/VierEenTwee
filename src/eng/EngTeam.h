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

        void cashUpDeps(int cash);

        void print(const std::string& message) const;

    public:
        void hireEmployees(int budget) override;

        void registerForSeason(log::Mediator *mediator);

        int buildCar(int budget);

        void carArrivesAtFactory(Car *car);

        void fixCar(int id);

        void improveCar(int id);

        Car *checkCarOutOfFactory(int id);

        void setRiskLevel(log::RiskLevel riskLevel);

        void toggleTransparency();
    };
}

#endif
