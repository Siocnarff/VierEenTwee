//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_CONTAINERPARTS_H
#define LOGISTICS_CONTAINERPARTS_H

#include "Container.h"
#include <list>

namespace log {
    class Box : public Container {
    private:
        std::list<Container *> elements;
    public:
        void addElement(Container *) override;

        Container *removeElement() override;

        void takeStock() override;

        ~Box() override;
    };

}

#endif //LOGISTICS_CONTAINERPARTS_H
