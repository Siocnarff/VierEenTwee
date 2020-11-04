//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_GARAGEEQUIPMENT_H
#define SRC_GARAGEEQUIPMENT_H

#include "Container.h"

namespace lg {
    class GarageEquipment : public Container {
    private:
        std::list <std::string> contents;
    public:
        GarageEquipment();

        GarageEquipment(std::list <std::string> insides);

        ~GarageEquipment() override;

        void print() override;
    };
}

#endif //SRC_GARAGEEQUIPMENT_H
