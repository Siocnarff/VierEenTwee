#ifndef RACING_PITSTOP_H
#define RACING_PITSTOP_H
#include "../eng/Car.h"
#include "../ppl/specialists/PitCrew.h"
//#include "Tires.h"
#include <list>
#include "../rce/pitstop/PitTeam.h"
namespace rce{
class Pitstop
{

private:
	std::list<ppl::Person*> TyreChangers;
	Tyres* tyre;
    eng::Car* car;
    PitTeam* PitStopTeam;
public:
    Pitstop(eng::Car* c,Tyres* t);

	void addCrew(std::list<ppl::Person*> p);

	void tyres(Tyres* t);

	bool stop();

	void setCar(eng::Car* c);

};
}
#endif
