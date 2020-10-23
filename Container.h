//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_CONTAINER_H
#define PREMODELLING_CONTAINER_H

#include <string>
using namespace std;

class ContainerState;

class Container {
    friend class BeingPacked;
    friend class InShipping;
    friend class ArrivedAtDestination;
private:
    ContainerState* containerCurrentState;
public:
    Container();
    virtual ~Container();
    virtual void takeStock() ;
    virtual void advanceState();
    string getState();

protected:
    virtual void addElement(Container *) ;
    virtual Container * removeElement();
    virtual void setState(ContainerState* state);

};

#endif //PREMODELLING_CONTAINER_H
