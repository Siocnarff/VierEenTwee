#include "HirePitCrew.h"
#include "../ppl/specialists/PitCrew.h"
ppl::Person *ppl::HirePitCrew::source(std::string job)
{
    Person* pit=new PitCrew(randomName(), true, 80 + rand() % 20);
    pit->setJobDescription(std::move(job));
    return pit;
}

