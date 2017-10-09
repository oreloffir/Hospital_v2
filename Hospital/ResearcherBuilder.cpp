#include "ResearcherBuilder.h"

ResearcherBuilder& ResearcherBuilder::setAreaOfResearch(const string& areaOfResearch)
{
	this->areaOfResearch = string(areaOfResearch);
	return *this;
}
Researcher* ResearcherBuilder::build()
{
	return new Researcher(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears, areaOfResearch);
}