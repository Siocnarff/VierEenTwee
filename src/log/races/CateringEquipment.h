//
// Created by jo-anne on 2020/10/26.
//

#ifndef SRC_CATERINGEQUIPMENT_H
#define SRC_CATERINGEQUIPMENT_H

#include "Container.h"

namespace lg {
    class CateringEquipment : public Container {
    private:
        std::list <std::string> contents;
    public:
        CateringEquipment(std::list <std::string> insides);
        rce::Tyres * unpack() override;
        ~CateringEquipment() override;
    };
}


#endif //SRC_CATERINGEQUIPMENT_H
