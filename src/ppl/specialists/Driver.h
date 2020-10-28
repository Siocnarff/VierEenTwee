#ifndef PEOPLE_DRIVER_H
#define PEOPLE_DRIVER_H

#include <Person.h>
#include <vector>

namespace ppl {
class Driver : public Person {

	private:
		int xp;
		std::vector<int> homeTracks;

	public:
        Driver(std::string n, bool d, int s);

        void addHomeTrack(int trackId);

		bool isHomeTrack(int trackId);

		int getXp() const;

		void setXp(int xp);
	};
}

#endif
