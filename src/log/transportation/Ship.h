//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_SHIP_H
#define SRC_SHIP_H

#include "TransportHandler.h"

namespace log{
    class Ship : public TransportHandler {
    public:
        void transport(Race *fromLocation, Race *destination, eng::Car *car = nullptr) override;
    };
}

#endif //SRC_SHIP_H
