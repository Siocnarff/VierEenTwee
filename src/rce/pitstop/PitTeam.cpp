#include "PitTeam.h"

#include <utility>
using namespace rce;

PitTeam::PitTeam(ppl::Person** p,Tyres* t,eng::Car* c)
{
    pitcrew=p;
    tyres=t;
    car=c;
}
void PitTeam::setcrew(ppl::Person** crew)
{
    pitcrew=std::move(crew);
}
void PitTeam::setTyres(Tyres* t)
{
    tyres=t;
}
