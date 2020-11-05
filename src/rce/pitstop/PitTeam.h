#ifndef PITSTOP_PITTEAM_H
#define PITSTOP_PITTEAM_H

#include "../ppl/Person.h"
#include <list>
#include "Tyres.h"
#include "../eng/Car.h"
#include "../rce/pitstop/SetOfTyres.h"
namespace rce
{
    class PitTeam
    {

    public:
        ppl::Person** pitcrew;
        Tyres* tyres;
        eng::Car* car;
    PitTeam(ppl::Person** p,Tyres* t,eng::Car* c);
    void setcrew(ppl::Person** crew);
    void setTyres(Tyres* t);
    virtual SetOfTyres* changeTyre()=0;
    };
}

#endif

