//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_FLY_H
#define SRC_FLY_H

#include <races/Race.h>
#include "TransportHandler.h"

namespace lg {
    class Fly : public TransportHandler {
    public:
        void transport(Race *fromLocation, Race *destination, eng::Car *car = nullptr) override;
        ~Fly();
    };
}


#endif //SRC_FLY_H
