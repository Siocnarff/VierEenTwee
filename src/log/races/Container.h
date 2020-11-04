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

    private:

    public:
        Container();

        virtual ~Container();

        virtual void print();

    protected:

        virtual void addElement(Container *);
    };

}

#endif //PREMODELLING_CONTAINER_H
