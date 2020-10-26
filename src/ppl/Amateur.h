#ifndef ppl_AMATEUR_H
#define ppl_AMATEUR_H

namespace ppl {
	class Amateur : public Person {

	public:
		std::string jobDescription;

		void printResume();

		void setJob(std::string job);
	};
}

#endif
