//
// Created by jo-anne on 2020/11/02.
//

#include <ppl/specialists/Driver.h>
#include "HireDriver.h"

using namespace ppl;

Person* HireDriver::source(std::string job) {
    auto* p = new Driver(randomName(), abs(rand()%2), 80 + rand() % 20);
    p->setJobDescription(std::move(job));
    return p;
}
