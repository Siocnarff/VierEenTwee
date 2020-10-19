//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_CONTAINER_H
#define PREMODELLING_CONTAINER_H
#include <string>
#include <list>
#include <iostream>
using namespace std;

class Container;

class ContainerState {
public:
    virtual void changeState(Container*) = 0;
    virtual string getState() = 0;
    virtual ~ContainerState() {};
};
class BeingPacked : public ContainerState {
public:
    void changeState(Container *) override;
    string getState() override;
    ~BeingPacked() {};
};
class InShipping : public ContainerState {
public:
    void changeState(Container*) override;
    string getState() override;
    ~InShipping() {};
};
class ArrivedAtDestination : public ContainerState {
public:
    void changeState(Container*) override;
    string getState() override;
    ~ArrivedAtDestination() {};
};


class Container {
private:
    ContainerState* containerCurrentState;
public:
    Container() {
        containerCurrentState = new BeingPacked();
    }
    virtual ~Container() {
        delete containerCurrentState;
    };
    virtual void addElement(Container *) {};
    virtual Container * removeElement() {};
    /**
     * @details This function prints out contents of container categorised into Boxes
     */
    virtual void takeStock() ;
    virtual void changeState();
    string getState();

//protected:
    virtual void setState(ContainerState* state);

};


class Box : public Container {
private:
    list<Container*> elements;
public:
    void addElement(Container *);
    Container * removeElement();
    void takeStock() override;
    ~Box();
};

class GarageEquipment : public Container {
private:
    list<string> contents;
public:
    GarageEquipment(list<string> insides);
    void takeStock() override;
    ~GarageEquipment();
};

class CateringEquipment: public Container {
private:
    list<string> contents;
public:
    void takeStock() override;
    ~CateringEquipment();
};


#endif //PREMODELLING_CONTAINER_H
