#ifndef PEOPLE_HIRERACINGDEP_H
#define PEOPLE_HIRERACINGDEP_H

#include <HumanResources.h>

namespace ppl {
    class HireRacingDep : public HumanResources {

    public:
       virtual Person * source(std::string job)=0;
    };
}

#endif
