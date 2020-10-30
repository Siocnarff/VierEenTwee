//
// Created by jo on 2020/10/17.
//

#ifndef PREMODELLING_STRATEGY_H
#define PREMODELLING_STRATEGY_H
#include "enums/RiskLevel.h"
#include <string>
#include <list>


namespace rce {

    class Strategy {
    private:
        log::RiskLevel riskLevel;
        std::list<int> tyres;
        std::string stratName;
    public:
        Strategy *execute() {
            return nullptr;
        }

        Strategy(int budget) {
            riskLevel = log::Aggressive;
        }

        log::RiskLevel getRiskLevel() {
            return riskLevel;
        }
    };

}

#endif //PREMODELLING_STRATEGY_H
