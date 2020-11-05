#include "ChangeTyre.h"
using namespace rce;
ChangeTyre::ChangeTyre(ppl::Person** p,Tyres* t,eng::Car* c):PitTeam(p,t,c) {}
SetOfTyres* ChangeTyre::changeTyre()
{
    SetOfTyres* set;
    set=tyres->getTyres(0);
    if(set==nullptr)
    {
        set = tyres->getTyres(1);
        if(set == nullptr)
        {
            set=tyres->getTyres(2);
        }
    }
    return set;
}
