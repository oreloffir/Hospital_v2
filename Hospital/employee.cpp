#include "employee.h"
#include <string.h>
#include <iostream>

int Employee::employeeIdGenerator = 1;

Employee::Employee(int id, const char* name, const char* dateOfBirth, eGender gender,
	const char* startWorkingDate, eRank employeeRank, double salary,
	const char* areaOfTraining, float seniorityYears = 0)
	:Person(id, name, dateOfBirth, gender)
{
	std::cout << "In Employee::Employee" << "---->" << this->name << std::endl;
	this->employeeId = Employee::employeeIdGenerator;
	++Employee::employeeIdGenerator;
	this->departments = new const Department*[Employee::MAX_NUMBER_OF_DEPATRMENTS];
	this->startWorkingDate = _strdup(startWorkingDate);
	this->employeeRank = employeeRank;
	this->salary = salary;
	this->areaOfTraining = _strdup(areaOfTraining);
	this->seniorityYears = seniorityYears;
	this->numberOfDepatments = 0;
}

Employee::Employee(const Employee& other)
	:Person(other) {
	std::cout << "In Employee::Employee(copy)" << "---->" << this->name << std::endl;
	*this = other;
}

const Employee& Employee::operator=(const Employee& other)
{
	std::cout << "In Employee::operator=" << std::endl;
	if (this != &other)
	{
		delete[] areaOfTraining;
		delete[] startWorkingDate;
		delete[] departments;

		employeeId = other.employeeId;
		departments = new const Department*[MAX_NUMBER_OF_DEPATRMENTS];
		for (int i = 0; i < numberOfDepatments; i++)
			departments[i] = other.departments[i];
		startWorkingDate = _strdup(other.startWorkingDate);
		employeeRank = other.employeeRank;
		salary = other.salary;
		areaOfTraining = _strdup(other.areaOfTraining);
		seniorityYears = other.seniorityYears;
	}
	return *this;
}

Employee::~Employee()
{
	std::cout << "In Employee::~Employee" << "---->" << this->name << std::endl;
	delete[] areaOfTraining;
	delete[] startWorkingDate;
	delete[] departments;
}

int Employee::getEmployeeId() const
{
	return this->employeeId;
}

const Department* const* Employee::getDepartments() const
{
	return this->departments;
}

const char* Employee::getStartWorkingDate() const
{
	return this->startWorkingDate;
}

Employee::eRank Employee::getEmployeeRank() const
{
	return this->employeeRank;
}

float Employee::getSeniorityYears() const
{
	return this->seniorityYears;
}

double Employee::getSalary() const
{
	return this->salary;
}

void Employee::work() const
{
	std::cout << "working" << std::endl;
	return;
}

void Employee::setSalary(double salary)
{
	this->salary = salary;
}

void Employee::updateSenorityYear(float senorityYears)
{
	this->seniorityYears = senorityYears;
}

const char* Employee::getAreaOfTraining() const
{
	return areaOfTraining;
}

void Employee::addDepartment(const Department* department)
{
	if (department == nullptr)
		return;
	if (numberOfDepatments == MAX_NUMBER_OF_DEPATRMENTS)
		return;
	removeDepartment(department->getName());
	departments[numberOfDepatments] = department;
	++numberOfDepatments;
}

void Employee::removeDepartment(const char* departmentName)
{
	int pos = -1;
	for (int i = 0; i < this->numberOfDepatments; i++)
		if (strcmp(departments[i]->getName(), departmentName) == 0)
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == numberOfDepatments - 1)
	{
		departments[pos] = nullptr;
		--numberOfDepatments;
		return;
	}
	for (int i = pos; i < this->numberOfDepatments && i < MAX_NUMBER_OF_DEPATRMENTS - 1; i++)
		departments[i] = departments[i + 1];
	--numberOfDepatments;
}

void Employee::toOs(std::ostream& os) const
{
	os << "-----------Employee Details-----------" << std::endl;
	os << "Employee id: " << "\t\t" << employeeId << std::endl;
	os << "Start working date: " << "\t" << startWorkingDate << std::endl;
	os << "Area of training: " << "\t" << areaOfTraining << std::endl;
	os << "Seniority years: " << "\t" << seniorityYears << std::endl;
	os << "Salary: " << "\t\t" << salary << std::endl;
	os << "Number of departments: " << "\t" << numberOfDepatments << std::endl;
	os << "Departments: " << std::endl;
	for (int i = 0; i < numberOfDepatments; i++)
	{
		os << "\t" << departments[i]->getName() << std::endl;
	}
}