#ifndef PEOPLE_AMATEUR_H
#define PEOPLE_AMATEUR_H

namespace people {
	class Amateur : people::Person {

	public:
		std::string jobDescription;

		void printResume();

		void setJob(std::string job);
	};
}

#endif
