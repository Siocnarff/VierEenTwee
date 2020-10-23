//
// Created by jo-anne on 2020/10/23.
//

#ifndef LOGISTICS_SUBSTATES_H
#define LOGISTICS_SUBSTATES_H

#include "ContainerState.h"

class BeingPacked : public ContainerState {
public:
    void nextState(Container *) override;
    string getState() override;
    ~BeingPacked();
};

class InShipping : public ContainerState {
public:
    void nextState(Container*) override;
    string getState() override;
    ~InShipping();
};

class ArrivedAtDestination : public ContainerState {
public:
    void nextState(Container *) override;
    string getState() override;
    ~ArrivedAtDestination();
};





#endif //LOGISTICS_SUBSTATES_H
