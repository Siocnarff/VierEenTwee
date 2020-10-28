#ifndef PEOPLE_DRIVER_H
#define PEOPLE_DRIVER_H

#include <Person.h>

namespace ppl {
class Driver : public Person {

	private:
		int xp = 0;
		int homeTracks[];

	public:
		bool isHomeTrack(int trackId);

		int getXp();

		void setXp(int xp);
	};
}

#endif
