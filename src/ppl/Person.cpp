#include "Person.h"

#include <utility>
#include <iostream>

using namespace ppl;

Person::Person(std::string n, bool hasDegree, int s) : name(std::move(n)), degree(hasDegree), skillLevel(s) {
    static int idCounter = 0;
    id = idCounter++;
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

std::string Person::getResume() {
    std::string resume = "RESUME:\n    id: ";
    resume.append(std::to_string(id));
    resume.append("\n    Name: ");
    resume.append(name);
    resume.append("\n    Has A Degree: ");
    resume.append(degree ? "Yes" : "No");
    resume.append("\n    Job Description: ");
    resume.append( jobDescription);
    resume.append("\n    Skill Level: ");
    resume.append(std::to_string(skillLevel));
    resume.append( "\n----");
    return resume;
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
