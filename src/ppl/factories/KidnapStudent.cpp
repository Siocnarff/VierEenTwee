#include "KidnapStudent.h"
#include <random>
#include <utility>

using namespace ppl;

Person *KidnapStudent::source(std::string job) {
    auto* p = new Person("NoName", false, 10 + int(random() % 50));
    p->setJobDescription(std::move(job));
    return p;
}
