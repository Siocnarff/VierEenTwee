#ifndef ppl_AMATEUR_H
#define ppl_AMATEUR_H

#include <Person.h>

namespace ppl {
	class Amateur : public Person {
    public:
        Amateur(std::string name, bool hasDegree, int skillLevel);
	};
}

#endif
