#ifndef DEV_SAFE_H
#define DEV_SAFE_H

#include "Risk.h"

namespace eng {
	class Safe : public Risk {

	public:
		int trySomethingNew() final;
	};
}

#endif
