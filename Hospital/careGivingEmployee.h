#ifndef CAREGIVINGEMPLOYEE_H_INCLUDED
#define CAREGIVINGEMPLOYEE_H_INCLUDED
#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

// Concrete class to distinguish between an employee that
// can give caring and an employee who can't like Researcher.
class CareGivingEmployee : virtual public Employee
{
public:
	CareGivingEmployee(int id, const string& name, const string& dateOfBirth, eGender gender,
		const string& startWorkingDate, eRank employeeRank, double salary,
		const string& areaOfTraining, float seniorityYears);
	CareGivingEmployee(const CareGivingEmployee& other) : Employee(other) {
		std::cout << "In CareGivingEmployee::CareGivingEmployee(copy)" << "---->" << this->name << std::endl;
	};
	virtual ~CareGivingEmployee();

	virtual void work() const override;
	void toOs(ostream& os) const override;
};

#endif // CAREGIVINGEMPLOYEE_H_INCLUDED
