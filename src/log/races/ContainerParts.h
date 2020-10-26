//
// Created by jo-anne on 2020/10/22.
//

#ifndef LOGISTICS_CONTAINERPARTS_H
#define LOGISTICS_CONTAINERPARTS_H

#include "Container.h"
#include <list>

class Box : public Container {
private:
    list<Container*> elements;
public:
    void addElement(Container *) override;
    Container * removeElement() override;
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



#endif //LOGISTICS_CONTAINERPARTS_H
