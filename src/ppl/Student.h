#ifndef PEOPLE_STUDENT_H
#define PEOPLE_STUDENT_H

namespace people {
	class Student : people::Person {

	public:
		std::string jobDescription;

		void printResume();

		void setJob(std::string job);
	};
}

#endif
