#ifndef AGGRESSIVESTRATEGY_H
#define AGGRESSIVESTRATEGY_H

#include "CreateStrategy.h"

namespace rce {
    class AggressiveStrategy : public CreateStrategy {
    public:
        AggressiveStrategy(int p, int *t, int risk);

        CreateStrategy *execute();

    };
}
#endif
