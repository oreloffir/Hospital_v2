#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include "careGivingEmployee.h"

class Doctor : public CareGivingEmployee
{
public:
	Doctor(CareGivingEmployee& CGEmployee, const char* fieldOfExpertise, int numOfDiplomas = 0);
	Doctor(const Doctor& other);
	const Doctor& operator=(const Doctor& other);
	virtual ~Doctor();

	int getNumOfDiplomas()              const;
	const char* getFieldOfExpertise()   const;

	void setNumOfDiplomas(int numOfDiplomas);
	void addDiploma();

	virtual void work() const;
	virtual void toOs(std::ostream& os) const override;
protected:
	int numOfDiplomas;
	char* fieldOfExpertise;

	void free();
};

#endif // DOCTOR_H_INCLUDED
