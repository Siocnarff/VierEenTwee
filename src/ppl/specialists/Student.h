#ifndef PEOPLE_STUDENT_H
#define PEOPLE_STUDENT_H

#include <Person.h>

namespace ppl {
	class Student : public Person {

	public:
		std::string jobDescription;

		void printResume();

		void setJob(std::string job);
	};
}

#endif
