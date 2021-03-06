#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include "careGivingEmployee.h"
#include <iostream>
#include <string>
using namespace std;


class Doctor : public CareGivingEmployee
{
public:
	Doctor(CareGivingEmployee& CGEmployee, const string& fieldOfExpertise, int numOfDiplomas = 0)
		: Employee(CGEmployee),
		CareGivingEmployee(CGEmployee),
		fieldOfExpertise(fieldOfExpertise),
		numOfDiplomas(numOfDiplomas) {};

	Doctor(const Doctor& other);
	const Doctor& operator=(const Doctor& other);
	
	virtual ~Doctor() {};

	int getNumOfDiplomas()					const;
	const string& getFieldOfExpertise()		const;

	void setNumOfDiplomas(int numOfDiplomas);
	void addDiploma();
	const Doctor& operator++();

	virtual void work() const;
	virtual void toOs(std::ostream& os) const override;
protected:
	int numOfDiplomas;
	string fieldOfExpertise;
};
#endif // DOCTOR_H_INCLUDED
