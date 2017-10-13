#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "person.h"
#include "department.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Employee : public Person
{
public:
	static constexpr int MAX_NUMBER_OF_DEPATRMENTS = 20;
	static int employeeIdGenerator; // starting from 0
	enum eRank { JUNIOR, SENIOR };
	struct employeeInfo
	{
		int id;
		string name;
		string dateOfBirth;
		eGender gender;
		string startWorkingDate;
		eRank employeeRank;
		double salary;
		string areaOfTraining;
		float seniorityYears;
	};

	Employee(int id, const string& name, const string& dateOfBirth, eGender gender,
		const string& startWorkingDate, eRank employeeRank, double salary,
		const string& areaOfTraining, float seniorityYears);
	Employee(const Employee& other);
	const Employee& operator=(const Employee& other);
	virtual ~Employee();

	int getEmployeeId()									const;
	const vector<const Department*> getDepartments()	const;
	int getCurrentNumOfDepartments()					const;
	const string& getStartWorkingDate()					const;
	eRank getEmployeeRank()								const;
	float getSeniorityYears()							const;
	double getSalary()									const;
	const string& getAreaOfTraining()					const;

	bool operator==(const Employee& other);
	virtual void toOs(std::ostream& os) const override;

	void setSalary(double salary);
	void updateSenorityYear(float senorityYears);
	void addDepartment(const Department* department);
	void removeDepartment(const string& departmentName);
	virtual void work() const = 0;

protected:
	int employeeId;
	vector<const Department*> departments;
	string startWorkingDate;
	eRank employeeRank;
	float seniorityYears;
	double salary;
	string areaOfTraining;
};
#endif // EMPLOYEE_H_INCLUDED
