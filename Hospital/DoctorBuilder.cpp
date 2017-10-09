#include "DoctorBuilder.h"

DoctorBuilder& DoctorBuilder::setFieldOfExpertise(const string& fieldOfExpertise)
{
	this->fieldOfExpertise = string(fieldOfExpertise);
	return *this;
}

DoctorBuilder& DoctorBuilder::setNumOfDiplomas(int numOfDiplomas)
{
	this->numOfDiplomas = numOfDiplomas;
	return *this;
}

Doctor* DoctorBuilder::build()
{
	CareGivingEmployee cge(this->id, this->name, this->dateOfBirth, this->gender, this->startWorkingDate, this->employeeRank, this->salary, this->areaOfTraining, this->seniorityYears);
	return new Doctor(cge, this->fieldOfExpertise, this->numOfDiplomas);
}
