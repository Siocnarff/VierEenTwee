//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_TRANSPORTHANDLER_H
#define PREMODELLING_TRANSPORTHANDLER_H
#include <iostream>
#include <races/Race.h>

#include "Colleague.h"

namespace log {

    class TransportHandler : public Colleague {
    private:
        TransportHandler *nextTransportationMethod;
    public:
        void hireEmployees(int budget) override;

        void addAMethod(TransportHandler *transport);

        /**
         * @param fromLocation: Race object to get location and europeanness
         * @param destination
         * @param car
         */
        virtual void transport(Race* fromLocation, Race *destination, eng::Car *car = nullptr);

        ~TransportHandler();
    };

}

#endif //PREMODELLING_TRANSPORTHANDLER_H
