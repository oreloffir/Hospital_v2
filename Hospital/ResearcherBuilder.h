#pragma once
#ifndef RESEARCHER_BUILDER_H
#define RESEARCHER_BUILDER_H
#include "IEmployeeBuilder.h"
#include "researcher.h"
class ResearcherBuilder : public IEmployeeBuilder
{
private:
	string areaOfResearch;
public:
	virtual ResearcherBuilder& setAreaOfResearch(const string& fieldOfExpertise);
	virtual Researcher* build() override;
};

#endif // !DOCTOR_BUILDER_H
