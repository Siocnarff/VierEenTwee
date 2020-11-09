#ifndef PEOPLE_HIREPITCREW_H
#define PEOPLE_HIREPITCREW_H


#include <HumanResources.h>

namespace ppl {
    class HirePitCrew : public HumanResources
    {

    public:
         Person* source(std::string job) override;
    };
}

#endif
