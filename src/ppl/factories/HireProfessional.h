#ifndef PEOPLE_HIREPROFESSIONAL_H
#define PEOPLE_HIREPROFESSIONAL_H

#include <HumanResources.h>

namespace ppl {

	class HireProfessional : public HumanResources {

	public:
		Person* source(std::string job) override;
	};
}

#endif