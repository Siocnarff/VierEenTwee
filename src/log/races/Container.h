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
        rce::Tyres packedTyres;

    public:
        Container();

        virtual ~Container();

        virtual rce::Tyres * unpack();

        virtual void pack(rce::Tyres);

    protected:
        virtual void addElement(Container *);

    };

}

#endif //PREMODELLING_CONTAINER_H
