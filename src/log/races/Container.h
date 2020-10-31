//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_CONTAINER_H
#define PREMODELLING_CONTAINER_H

#include <string>
#include <list>
#include <iostream>
#include "Tyres.h"


namespace lg {
    class ContainerState;

    class Container {
        friend class BeingPackedState;

        friend class InShippingState;

        friend class ArrivedState;

    private:
        ContainerState *containerCurrentState;
    public:
        Container();

        virtual ~Container();

        virtual rce::Tyres * unpack();
        virtual void repack(rce::Tyres);

        virtual void advanceState();

        std::string getState();

    protected:
        virtual void addElement(Container *);

        virtual Container *removeElement();

        virtual void setState(ContainerState *state);

    };

}

#endif //PREMODELLING_CONTAINER_H
