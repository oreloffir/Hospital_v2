#include "careGivingEmployee.h"
#include <iostream>

CareGivingEmployee::CareGivingEmployee(int id, const char* name,
	const char* dateOfBirth, eGender gender, const char* startWorkingDate,
	eRank employeeRank, double salary, const char* areaOfTraining, float seniorityYears)
	:Employee(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears)
{
	std::cout << "In CareGivingEmployee::CareGivingEmployee" << "---->" << this->name << std::endl;
}

CareGivingEmployee::~CareGivingEmployee()
{
	std::cout << "In CareGivingEmployee::~CareGivingEmployee" << "---->" << this->name << std::endl;
}

void CareGivingEmployee::work() const
{
	std::cout << "CareGivingEmployee " << name <<" WORKING!" << std::endl;
}

void CareGivingEmployee::toOs(ostream& os) const
{
	os << "-----------CareGivingEmployee Details-----------" << endl; 
}