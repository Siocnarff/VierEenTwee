//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_ENGDEPT_H
#define PREMODELLING_ENGDEPT_H

#include "Colleague.h"
#include "RiskLevel.h"

using namespace log;

class EngDept: public log::Colleague {
public:
    ~EngDept();
    void HireEmployees(int budget) override;
    int buildCar(int budget, RiskLevel);
    void carArrivesAtFactory(eng::Car*);
    void fixCar(int id);
    void improveCar(int id);
    void updateCar(int id);
    eng::Car* checkCarOutOfFactory(int id);
};




#endif //PREMODELLING_ENGDEPT_H
