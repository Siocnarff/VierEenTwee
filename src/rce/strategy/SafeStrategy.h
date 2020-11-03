#ifndef SAFESTRATEGY_H
#define SAFESTRATEGY_H

#include "CreateStrategy.h"


namespace rce {
    class SafeStrategy : public CreateStrategy
   {
    public:
        CreateStrategy *execute() override;

        SafeStrategy(int p, int *t, log::RiskLevel risk);
    };
}
#endif
