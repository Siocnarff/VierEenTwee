#include "Pitstop.h"

#include <utility>
using namespace rce;

Pitstop::Pitstop(eng::Car *c, Tyres *t)
{
    car=c;
    tyre=t;
}

void Pitstop::addCrew(std::list<ppl::Person*> p)
{
    TyreChangers=std::move(p);
}

void Pitstop::tyres(Tyres* t)
{
	tyre=t;
}

bool Pitstop::stop()
{
    //todo see how to change tyres on the car
}

void Pitstop::setCar(eng::Car* c)
{
	car=c;
}

