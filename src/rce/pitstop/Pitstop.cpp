#include "Pitstop.h"

//#include <utility>
using namespace rce;

Pitstop::Pitstop(eng::Car *c, Tyres *t,ppl::Person** p)
{
    car=c;
    tyre=t;
    PitStopTeam=new ChangeTyre(p,t,c);
}

void Pitstop::addCrew(ppl::Person** p)
{
    TyreChangers=p;
}

void Pitstop::tyres(Tyres* t)
{
	tyre=t;
}

SetOfTyres* Pitstop::stop()
{
    std::string output = "\t\t**Pitstop: change tyres**\n";
    pr::Doc::detail(output);
    return PitStopTeam->changeTyre();
}

void Pitstop::setCar(eng::Car* c)
{
	car=c;
}

