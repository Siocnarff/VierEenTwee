#include "HireStrategist.h"
#include "../ppl/specialists/Strategist.h"
ppl::Person *ppl::HireStrategist::source(std::string job)
{
    Person* strat=new Strategist(randomName(), true, 80 + rand() % 20);
    strat->setJobDescription(std::move(job));
    return strat;
}