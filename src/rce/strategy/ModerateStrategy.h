#ifndef MODERATESTRATEGY_H
#define MODERATESTRATEGY_H

#include "CreateStrategy.h"

namespace rce {

    class ModerateStrategy : public CreateStrategy {
    public:
        CreateStrategy *execute();
        ModerateStrategy(int p, int *t, lg::RiskLevel risk);
//        ~ModerateStrategy();
    };
}
#endif
