#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "person.h"
#include "department.h"

class Employee : public Person
{
public:
	static constexpr int MAX_NUMBER_OF_DEPATRMENTS = 20;
	static int employeeIdGenerator; // starting from 0
	enum eRank { JUNIOR, SENIOR };
	struct employeeInfo
	{
		int id;
		char* name;
		char* dateOfBirth;
		eGender gender;
		char* startWorkingDate;
		eRank employeeRank;
		double salary;
		char* areaOfTraining;
		float seniorityYears;
	};

	Employee(int id, const char* name, const char* dateOfBirth, eGender gender,
		const char* startWorkingDate, eRank employeeRank, double salary,
		const char* areaOfTraining, float seniorityYears);
	Employee(const Employee& other);

	const Employee& operator=(const Employee& other);

	virtual ~Employee();

	int getEmployeeId()							const;
	const Department* const* getDepartments()	const;
	const char* getStartWorkingDate()			const;
	eRank getEmployeeRank()						const;
	float getSeniorityYears()					const;
	double getSalary()							const;
	const char* getAreaOfTraining()				const;

	virtual void toOs(std::ostream& os) const override;

	void setSalary(double salary);
	void updateSenorityYear(float senorityYears);
	void addDepartment(const Department* department);
	void removeDepartment(const char* departmentName);
	virtual void work() const = 0;

protected:
	int employeeId;
	const Department** departments;
	int numberOfDepatments;
	char* startWorkingDate;
	eRank employeeRank;
	float seniorityYears;
	double salary;
	char* areaOfTraining;
};
#endif // EMPLOYEE_H_INCLUDED
