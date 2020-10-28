//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_GARAGEEQUIPMENT_H
#define SRC_GARAGEEQUIPMENT_H

#include "Container.h"

namespace log {
    class GarageEquipment : public Container {
    private:
        std::list <std::string> contents;
    public:
        GarageEquipment(std::list <std::string> insides);

        Tyres * unpack() override;

        ~GarageEquipment() override;
    };
}

#endif //SRC_GARAGEEQUIPMENT_H
