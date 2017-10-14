#include "inspection.h"
#include <iostream>

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