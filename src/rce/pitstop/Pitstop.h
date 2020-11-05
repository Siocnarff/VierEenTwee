#ifndef RACING_PITSTOP_H
#define RACING_PITSTOP_H
#include "../eng/Car.h"
#include "../ppl/specialists/PitCrew.h"
//#include "Tires.h"
#include <list>
#include "../rce/pitstop/PitTeam.h"
#include "../rce/pitstop/SetOfTyres.h"
#include "../rce/pitstop/ChangeTyre.h"
namespace rce{
class Pitstop
{

private:
    ppl::Person** TyreChangers;
	Tyres* tyre;
    eng::Car* car;
    PitTeam* PitStopTeam;
public:
    Pitstop(eng::Car* c,Tyres* t,ppl::Person** p);

	void addCrew(ppl::Person** p);

	void tyres(Tyres* t);

    SetOfTyres* stop();

	void setCar(eng::Car* c);

};
}
#endif
