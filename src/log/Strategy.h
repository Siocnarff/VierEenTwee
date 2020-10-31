//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_STRATEGY_H
#define PREMODELLING_STRATEGY_H
#include "enums/RiskLevel.h"
#include <string>
#include <list>

using namespace lg;

class Strategy {
private:
    RiskLevel riskLevel;
    std::list<int> tyres;
    std::string stratName;
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
