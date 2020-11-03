#ifndef PEOPLE_HIRESTRATEGIST_H
#define PEOPLE_HIRESTRATEGIST_H

#include "HireRacingDep.h"

namespace ppl {
    class HireStrategist : public HireRacingDep{

    public:
        Person* source(std::string job) override;
    };
}

#endif
