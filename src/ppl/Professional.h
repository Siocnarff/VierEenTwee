#ifndef PEOPLE_PROFESSIONAL_H
#define PEOPLE_PROFESSIONAL_H

namespace people {
	class Professional : people::Person {

	public:
		std::string jobDescription;

		void printResume();

		void setJob(std::string job);
	};
}

#endif
