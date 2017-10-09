#ifndef I_EMPLOYEE_BUILDER_H
#define I_EMPLOYEE_BUILDER_H
#include "employee.h"
#include <string>
#include <iostream>

using namespace std;

class IEmployeeBuilder
{
protected:
	int id;
	string name;
	string dateOfBirth;
	string startWorkingDate;
	string areaOfTraining;
	Person::eGender gender;
	Employee::eRank employeeRank;
	double salary;
	float seniorityYears;
public:
	IEmployeeBuilder();
	virtual IEmployeeBuilder& setId(int id);
	virtual IEmployeeBuilder& setName(const string& name);
	virtual IEmployeeBuilder& setDateOfBirth(const string& dateOfBirth);
	virtual IEmployeeBuilder& setStartWorkingDate(const string& startWorkingDate);
	virtual IEmployeeBuilder& setAreaOfTraining(const string& areaOfTraining);
	virtual IEmployeeBuilder& setGender(Person::eGender gender);
	virtual IEmployeeBuilder& setEmployeeRank(Employee::eRank employeeRank);
	virtual IEmployeeBuilder& setSalary(double salary);
	virtual IEmployeeBuilder& setSeniorityYears(float seniorityYears);
	virtual Employee* build() = 0;
};

#endif // !I_EMPLOYEE_BUILDER
