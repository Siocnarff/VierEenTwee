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
    class EngTeam final : public lg::Colleague {

    private:
        Garage garage;
        BlueprintStore blueprintStore;
        WindTunnel windTunnel = WindTunnel::instance();
        ComponentSimulator simulator;
        Department *department[5] = {nullptr};

        void cashUpDeps(int cash);


    public:
        EngTeam();

        ~EngTeam() final;

        void hireEmployees(int budget) final;

        void registerForSeason(lg::Mediator *mediator);

        void resetTickets();

        static int generateId();

        int buildCar(int budget);

        void carArrivesAtFactory(Car *car);

        void fixCar(int id);

        void improveCar(int id, bool usingWindTunnel);

        Car *checkCarOutOfFactory(int id);

        void setRiskLevel(lg::RiskLevel riskLevel);
    };
}

#endif
