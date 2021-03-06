//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_MEDIATOR_H
#define LOGISTICS_MEDIATOR_H

#include <races/Race.h>
#include "Car.h"
#include "containers/Container.h"

namespace lg {

    class Mediator {
    protected:
        virtual ~Mediator() = default;

        virtual void sendCarToFactory(std::vector<eng::Car *> cars, Race* currentRace, bool isBroken) = 0;

        //virtual void containerHasBeenPacked(Container *) = 0;

        //virtual void requestContainerStateChange(bool isEuropeanRace) = 0;

        virtual void orderTyres(int* tyreOrder) = 0;

        virtual void moveDrivers(std::vector<ppl::Driver*>) = 0;

    public:
        friend class Colleague;
    };

}

#endif //LOGISTICS_MEDIATOR_H