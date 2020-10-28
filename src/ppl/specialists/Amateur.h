#ifndef ppl_AMATEUR_H
#define ppl_AMATEUR_H

#include <Person.h>

namespace ppl {
	class Amateur : public Person {
        Amateur(std::string n, bool d, int s);
	};
}

#endif
