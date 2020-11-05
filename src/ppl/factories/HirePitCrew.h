#ifndef PEOPLE_HIREPITCREW_H
#define PEOPLE_HIREPITCREW_H

#include "HireRacingDep.h"

namespace ppl {
    class HirePitCrew : public HireRacingDep
    {

    public:
         Person* source(std::string job) override;
    };
}

#endif
