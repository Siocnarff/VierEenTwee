#ifndef DEV_AGRESSIVE_H
#define DEV_AGRESSIVE_H

#import "Risk.h"

namespace dev {
	class Agressive : Risk {


	public:
		int trySomethingNew() final;
	};
}

#endif
