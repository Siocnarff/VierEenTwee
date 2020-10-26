#ifndef PEOPLE_PERSON_H
#define PEOPLE_PERSON_H

#include <string>

namespace ppl {
	class Person {

	private:
		std::string name;
		bool degree;
		int skillLevel;
		int id;

	public:
		Person(std::string n, bool d, int s);

		std::string getName();

		bool hasDegree();

		int getSkillLevel();

		void printResume();

		int getId();
	};
}

#endif
