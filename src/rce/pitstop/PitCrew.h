#ifndef RACING_PITCREW_H
#define RACING_PITCREW_H
namespace racing{
class PitCrew {


public:
	PitCrew();

	void setCar(RaceDaysIterator* c);

	virtual void changetyres() = 0;
};
}
#endif
