#ifndef PEOPLE_STUDENT_H
#define PEOPLE_STUDENT_H

#include <Person.h>

namespace ppl {
	class Student : public Person {
        Student(std::string name, bool hasDegree, int skillLevel);
	};
}

#endif
