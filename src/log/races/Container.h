//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_CONTAINER_H
#define PREMODELLING_CONTAINER_H

#include <string>
#include <list>
#include <iostream>
#include "Tyres.h"


namespace log {
    class ContainerState;

    class Container {

    private:

    public:
        Container();

        virtual ~Container();

        virtual void unpack();

        virtual void pack();    //Nodig om die tyres te vervang met die verweerdes

    protected:
        virtual void addElement(Container *);

        virtual void print();

    };

}

#endif //PREMODELLING_CONTAINER_H
