#ifndef PEOPLE_HUMANRESOURCES_H
#define PEOPLE_HUMANRESOURCES_H

#include <string>
#include "Person.h"

namespace ppl {
    class HumanResources {

    public:
        Person *hire(std::string job);

    protected:
        virtual Person *source() = 0;
    };
}

#endif
