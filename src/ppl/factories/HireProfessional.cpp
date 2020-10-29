#include <Person.h>
#include "HireProfessional.h"

using namespace ppl;

Person* HireProfessional::source(std::string job) {
    auto* p = new Person(randomName(), true, 80 + rand() % 20);
    p->setJobDescription(std::move(job));
    return p;
}
