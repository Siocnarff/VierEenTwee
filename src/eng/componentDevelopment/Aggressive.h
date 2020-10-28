#ifndef DEV_AGRESSIVE_H
#define DEV_AGRESSIVE_H

#include "Risk.h"

namespace eng {
	class Aggressive : public Risk {


	public:
		int trySomethingNew() final;
	};
}

#endif
