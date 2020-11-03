#ifndef RACING_STRATEGIST_H
#define RACING_STRATEGIST_H
#include <Person.h>
namespace ppl{
    class Strategist:public Person
     {
    public:
        Strategist(std::string name, bool hasDegree, int skillLevel);
    };
}
#endif
