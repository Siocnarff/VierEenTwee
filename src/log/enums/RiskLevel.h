#ifndef ENG_RISKLEVEL_H
#define ENG_RISKLEVEL_H

namespace lg {
	enum RiskLevel {
		Safe, 
		Moderate, 
		Aggressive
	};

	RiskLevel randomRL() {
        switch (rand()%3) {
            case 0:
                return Safe;
            case 1:
                return Moderate;
            case 2:
                return Aggressive;
        }
	}
}

#endif
