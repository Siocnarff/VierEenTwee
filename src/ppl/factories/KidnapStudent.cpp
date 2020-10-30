#include "KidnapStudent.h"
#include <random>
#include <utility>

using namespace ppl;

Person *KidnapStudent::source(std::string job) {
    auto* p = new Person(randomName(), false, 10 + rand() % 50);
    p->setJobDescription(std::move(job));
    return p;
}
