//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_TRANSPORTHANDLER_H
#define PREMODELLING_TRANSPORTHANDLER_H
#include <iostream>
#include <races/Race.h>

using namespace std;

#include "Colleague.h"

namespace lg {

    class TransportHandler : public Colleague {
    private:
        TransportHandler *nextTransportationMethod = nullptr;
    public:
        ~TransportHandler();

        void hireEmployees(int budget) override;

        void addAMethod(TransportHandler *transport);

        virtual void transport(Race *fromLocation, Race *destination, eng::Car *car = nullptr);
    };

}

#endif //PREMODELLING_TRANSPORTHANDLER_H
