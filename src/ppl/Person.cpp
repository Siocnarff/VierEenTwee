#include "Person.h"

#include <utility>
#include <iostream>

using namespace ppl;

Person::Person(std::string n, bool hasDegree, int s) : name(std::move(n)), degree(hasDegree), skillLevel(s) {
    id = Person::idCounter++;
}

std::string Person::getName() {
	return name;
}

bool Person::hasDegree() const {
    return degree;
}

int Person::getSkillLevel() const {
	return skillLevel;
}

void Person::printResume() {
	std::cout   << "RESUME:\n"
                << "    id: " << id  << std::endl
                << "    Name: " << name << std::endl
                << "    Has A Degree: " << (degree ? "Yes" : "No") << std::endl
                << "    Job Description: " << jobDescription << std::endl
                << "    Skill Level: " << skillLevel << std::endl
                << "----\n";
}

int Person::getId() const {
	return id;
}

std::string Person::getJobDescription() {
    return jobDescription;
}

void Person::setJobDescription(std::string job) {
    jobDescription = std::move(job);
}

bool Person::isProfessional() const {
    return false;
}
