#ifndef PEOPLE_HIRESTRATEGIST_H
#define PEOPLE_HIRESTRATEGIST_H


#include <HumanResources.h>

namespace ppl {
    class HireStrategist : public HumanResources {

    public:
        Person* source(std::string job) override;
    };
}

#endif
