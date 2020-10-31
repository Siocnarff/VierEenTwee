//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_MEDIATOR_H
#define LOGISTICS_MEDIATOR_H

#include "Car.h"
#include "races/Container.h"

namespace log {

    class Mediator {
    protected:
        virtual void sendCarToFactory(eng::Car *) = 0;

        virtual void containerHasBeenPacked(Container *) = 0;

        //virtual void requestContainerStateChange(bool isEuropeanRace) = 0;

        virtual void orderTyres(int* tyreOrder) = 0;

    public:
        friend class Colleague;
    };

}

#endif //LOGISTICS_MEDIATOR_H