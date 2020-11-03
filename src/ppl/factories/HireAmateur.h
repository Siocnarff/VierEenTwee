#ifndef PEOPLE_HIREAMATEUR_H
#define PEOPLE_HIREAMATEUR_H

#include <HumanResources.h>

namespace ppl {
	class HireAmateur : public HumanResources {

	public:
		Person* source(std::string job) override;
	};
}

#endif
