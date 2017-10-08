#include "inspection.h"
#include <iostream>

Inspection::Inspection(const Visit::VisitInfo visitInfo, const char* typeOfInspection)
:	Visit(visitInfo.date, visitInfo.cause, visitInfo.department, visitInfo.patient, visitInfo.typeOfCare) {
	this->typeOfInspection = _strdup(typeOfInspection);
}

Inspection::~Inspection()
{
	delete[] typeOfInspection;
}

const char* Inspection::getTypeOfInspection() const
{
	return this->typeOfInspection;
}

Inspection::eLabResult Inspection::getLabResult() const
{
	return this->labResult;
}

void Inspection::setTypeOfInspection(const char* typeOfInspection) 
{
	delete[] this->typeOfInspection;
	this->typeOfInspection = _strdup(typeOfInspection);
}

void Inspection::setLabResult(Inspection::eLabResult labResult)
{
	this->labResult = labResult;
}

const char* Inspection::labResults[] = { "POSITIVE", "NEGETIVE" };

const char* Inspection::getLabResultName() const
{
	return Inspection::labResults[labResult];
}

void Inspection::toOs(std::ostream& os) const
{
	os << "Type of inspection: " << "\t\t" << getTypeOfInspection() << std::endl;
}