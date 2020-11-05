//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_CONTAINERPARTS_H
#define LOGISTICS_CONTAINERPARTS_H

#include "Container.h"
#include <list>

namespace lg {
    class Box : public Container {
    private:
        std::list<Container *> elements;
    public:
        Box();

        void addElement(Container *) override;

        ~Box() override;

        void print() override;
    };

}

#endif //LOGISTICS_CONTAINERPARTS_H
