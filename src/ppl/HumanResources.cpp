#include "HumanResources.h"

using namespace ppl;

Person* HumanResources::hire(std::string job) {
	return source(job);
}
