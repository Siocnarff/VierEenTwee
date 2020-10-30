#include "Professional.h"

using namespace ppl;

Professional::Professional(std::string name, bool hasDegree, int skillLevel) : Person(name, hasDegree, skillLevel) {}

bool Professional::isProfessional() const {
    return true;
}
