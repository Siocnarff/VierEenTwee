#ifndef PEOPLE_PROFESSIONAL_H
#define PEOPLE_PROFESSIONAL_H

#include <Person.h>

namespace ppl {
	class Professional : public Person {
	public:
        Professional(std::string name, bool hasDegree, int skillLevel);

        bool isProfessional() const override;
	};
}

#endif
