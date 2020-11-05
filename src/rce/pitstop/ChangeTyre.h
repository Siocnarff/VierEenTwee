#ifndef RACING_CHANGETYRE_H
#define RACING_CHANGETYRE_H

#include "../rce/pitstop/PitTeam.h"

namespace rce{
class ChangeTyre : public PitTeam
{

public:
    ChangeTyre(ppl::Person** p,Tyres* t,eng::Car* c);
	 SetOfTyres* changeTyre();
};
}
#endif
