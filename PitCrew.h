#ifndef PITCREW_H
#define PITCREW_H

class PitCrew {


public:
	PitCrew();

	void setCar(RaceDaysIterator* c);

	virtual void changetyres() = 0;
};

#endif
