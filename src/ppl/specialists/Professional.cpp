#include "Professional.h"

using namespace ppl;

Professional::Professional(std::string n, bool d, int s) : Person(n, d, s) {}

bool Professional::isProfessional() const {
    return true;
}
