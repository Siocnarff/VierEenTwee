//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_SHIP_H
#define SRC_SHIP_H

#include <races/Race.h>
#include "TransportHandler.h"

namespace lg{
    class Ship : public TransportHandler {
    public:
        void transport(Race *fromLocation, Race *destination, eng::Car *car = nullptr) override;
        ~Ship();
    };
}

#endif //SRC_SHIP_H
