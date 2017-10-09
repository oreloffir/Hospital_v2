#include "NurseBuilder.h"
Nurse* NurseBuilder::build()
{
	CareGivingEmployee cge(this->id, this->name, this->dateOfBirth, this->gender, this->startWorkingDate, this->employeeRank, this->salary, this->areaOfTraining, this->seniorityYears);
	return new Nurse(cge);
}