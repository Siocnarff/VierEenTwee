#ifndef DEV_AGRESSIVE_H
#define DEV_AGRESSIVE_H

#import "Risk.h"

namespace eng {
	class Agressive : public Risk {


	public:
		int trySomethingNew() final;
	};
}

#endif
