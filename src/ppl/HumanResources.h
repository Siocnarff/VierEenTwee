#ifndef PEOPLE_HUMANRESOURCES_H
#define PEOPLE_HUMANRESOURCES_H

#include <string>
#include "Person.h"

namespace ppl {
    class HumanResources {

    public:
        HumanResources();

        Person *hire(std::string job);

    protected:
        virtual Person *source(std::string job) = 0;

        static std::string randomName();
    };
}

#endif
