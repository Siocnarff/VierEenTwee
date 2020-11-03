#ifndef RACING_PITCREW_H
#define RACING_PITCREW_H
#include <Person.h>
#include "../eng/Car.h"
namespace ppl{
class PitCrew:public Person
{

public:
	PitCrew(std::string name, bool hasDegree, int skillLevel);
};
}
#endif
