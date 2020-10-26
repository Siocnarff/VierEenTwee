//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_TRANSPORTMETHODS_H
#define LOGISTICS_TRANSPORTMETHODS_H

#include "TransportHandler.h"

namespace log {
    class Road : public TransportHandler {
    public:
        void transport(Race *fromLocation, Race *destination, eng::Car *car = nullptr) override;
    };
}



#endif //LOGISTICS_TRANSPORTMETHODS_H
