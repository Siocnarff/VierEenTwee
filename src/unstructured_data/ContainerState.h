//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_CONTAINERSTATE_H
#define LOGISTICS_CONTAINERSTATE_H

#include "Container.h"
#include <string>
using namespace std;

class Container;

class ContainerState {
public:
    virtual void nextState(Container*) = 0;
    virtual string getState() = 0;
    virtual ~ContainerState();
};


#endif //LOGISTICS_CONTAINERSTATE_H
