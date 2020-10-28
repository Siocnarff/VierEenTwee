#include <Person.h>
#include "HireAmateur.h"

using namespace ppl;

Person* HireAmateur::source(std::string job) {
    auto* p = new Person(randomName(), false, 50 + int(random() % 40));
    p->setJobDescription(std::move(job));
    return p;
}
