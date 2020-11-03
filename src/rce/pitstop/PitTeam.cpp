#include "PitTeam.h"

#include <utility>
using namespace rce;

PitTeam::PitTeam(std::list<ppl::Person*> p,Tyres* t,eng::Car* c)
{
    pitcrew=p;
    tyres=t;
    car=c;
}
void PitTeam::setcrew(std::list<ppl::Person*> crew)
{
    pitcrew=std::move(crew);
}
void PitTeam::setTyres(Tyres* t)
{
    tyres=t;
}
