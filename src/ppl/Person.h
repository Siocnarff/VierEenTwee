#ifndef PEOPLE_PERSON_H
#define PEOPLE_PERSON_H

#include <string>

namespace ppl {
	class Person {
	private:
		std::string name;
		std::string jobDescription;
		bool degree;
		int skillLevel;
		int id;

        static int generateId();

	public:
		Person(std::string name, bool hasDegree, int skillLevel);

		std::string getName();

		std::string getJobDescription();

		void setJobDescription(std::string job);

		bool hasDegree() const;

		int getSkillLevel() const;

		std::string getResume();

		int getId() const;

        virtual bool isProfessional() const;
    };
}

#endif
