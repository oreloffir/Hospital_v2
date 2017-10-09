#include "inspection.h"
#include <iostream>

Inspection::Inspection(const Visit::VisitInfo visitInfo, const string typeOfInspection)
:	Visit(visitInfo.date, visitInfo.cause, visitInfo.department, visitInfo.patient, visitInfo.typeOfCare) {
	this->typeOfInspection = typeOfInspection;
}

Inspection::~Inspection()
{
	//delete[] typeOfInspection; TODO
}

const string Inspection::getTypeOfInspection() const
{
	return this->typeOfInspection;
}

Inspection::eLabResult Inspection::getLabResult() const
{
	return this->labResult;
}

void Inspection::setTypeOfInspection(const string typeOfInspection) 
{
	//delete[] this->typeOfInspection; // TODO
	this->typeOfInspection = typeOfInspection;
}

void Inspection::setLabResult(Inspection::eLabResult labResult)
{
	this->labResult = labResult;
}

const string Inspection::labResults[] = { "POSITIVE", "NEGETIVE" };

const string Inspection::getLabResultName() const
{
	return Inspection::labResults[labResult];
}

void Inspection::toOs(std::ostream& os) const
{
	os << "Type of inspection: " << "\t\t" << getTypeOfInspection() << std::endl;
}