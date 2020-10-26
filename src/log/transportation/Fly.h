//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_FLY_H
#define SRC_FLY_H

#include "TransportHandler.h"

namespace log {
    class Fly : public TransportHandler {
    public:
        void transport(Race *fromLocation, Race *destination, eng::Car *car = nullptr) override;
    };
}


#endif //SRC_FLY_H
