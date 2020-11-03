#ifndef PITSTOP_PITTEAM_H
#define PITSTOP_PITTEAM_H

#include "../ppl/Person.h"
#include <list>
#include "Tyres.h"
#include "../eng/Car.h"
namespace rce
{
    class PitTeam
    {
    private:
        std::list<ppl::Person*> pitcrew;
        Tyres* tyres;
        eng::Car* car;
    public:
    PitTeam(std::list<ppl::Person*> p,Tyres* t,eng::Car* c);
    void setcrew(std::list<ppl::Person*> crew);
    void setTyres(Tyres* t);
    virtual bool changeTyre()=0;
    };
}

#endif

