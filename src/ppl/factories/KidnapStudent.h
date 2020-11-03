#ifndef PEOPLE_KIDNAPSTUDENT_H
#define PEOPLE_KIDNAPSTUDENT_H

#include <HumanResources.h>
#include <Person.h>

namespace ppl {
	class KidnapStudent : public HumanResources {

	public:
		Person* source(std::string job) override;
	};
}

#endif
