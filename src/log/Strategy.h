//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_STRATEGY_H
#define PREMODELLING_STRATEGY_H
#include "enums.h"
#include <string>
#include <list>
using namespace std;

class Strategy {
private:
    RiskLevel riskLevel;
    list<TyresCompounds> tyres;
    string stratName;
public:
    Strategy* execute() {
        return nullptr;
    }

    Strategy(int budget) {

    }

    RiskLevel getRiskLevel() {
        return riskLevel;
    }
};

#endif //PREMODELLING_STRATEGY_H
