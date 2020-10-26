#ifndef PEOPLE_DRIVER_H
#define PEOPLE_DRIVER_H

namespace people {
	class Driver : people::Person {

	private:
		int xp;
		int homeTracks[];

	public:
		bool isHomeTrack(int trackId);

		int getXp();

		void setXp(int xp);
	};
}

#endif
