#ifndef PEOPLE_DRIVER_H
#define PEOPLE_DRIVER_H

namespace ppl {
	class Driver : public Person {

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
