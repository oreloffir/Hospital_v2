#include "IEmployeeBuilder.h"
IEmployeeBuilder::IEmployeeBuilder()
	:gender(Person::MALE),
	employeeRank(Employee::SENIOR),
	salary(0),
	seniorityYears(0)
{}

IEmployeeBuilder & IEmployeeBuilder::setId(int id)
{
	this->id = id;
	return *this;
}

IEmployeeBuilder& IEmployeeBuilder::setName(const string& name)
{
	this->name = string(name);
	return *this;
}

IEmployeeBuilder& IEmployeeBuilder::setDateOfBirth(const string& dateOfBirth)
{
	this->dateOfBirth = string(dateOfBirth);
	return *this;
}

IEmployeeBuilder& IEmployeeBuilder::setStartWorkingDate(const string& startWorkingDate)
{
	this->startWorkingDate = string(startWorkingDate);
	return *this;
}

IEmployeeBuilder& IEmployeeBuilder::setAreaOfTraining(const string& areaOfTraining)
{
	this->areaOfTraining = string(areaOfTraining);
	return *this;
}

IEmployeeBuilder & IEmployeeBuilder::setGender(Person::eGender gender)
{
	this->gender = gender;
	return *this;
}

IEmployeeBuilder & IEmployeeBuilder::setEmployeeRank(Employee::eRank employeeRank)
{
	this->employeeRank = employeeRank;
	return *this;
}

IEmployeeBuilder & IEmployeeBuilder::setSalary(double salary)
{
	this->salary = salary;
	return *this;
}

IEmployeeBuilder & IEmployeeBuilder::setSeniorityYears(float seniorityYears)
{
	this->seniorityYears = seniorityYears;
	return *this;
}


