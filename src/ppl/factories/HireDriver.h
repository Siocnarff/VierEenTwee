//
// Created by jo-anne on 2020/11/02.
//

#ifndef VIEREENTWEE_HIREDRIVER_H
#define VIEREENTWEE_HIREDRIVER_H
#include <ppl/HumanResources.h>

namespace ppl {
    class HireDriver : public HumanResources {

    public:
        Person* source(std::string job);
    };
}


#endif //VIEREENTWEE_HIREDRIVER_H
