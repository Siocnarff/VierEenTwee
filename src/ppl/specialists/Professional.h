#ifndef PEOPLE_PROFESSIONAL_H
#define PEOPLE_PROFESSIONAL_H

namespace ppl {
	class Professional : public Person {

	public:
		std::string jobDescription;

		void printResume();

		void setJob(std::string job);
	};
}

#endif
