#ifndef NURSE_H_INCLUDED
#define NURSE_H_INCLUDED

#include "careGivingEmployee.h"

class Nurse : public CareGivingEmployee
{

public:
	Nurse(CareGivingEmployee& CGEmployee, int maxNumOfDuties);
	Nurse(const Nurse& other) = delete;
	Nurse& operator=(const Nurse& other) = delete;

	virtual ~Nurse();

	const char* const* getDuties() const;
	int getMaxNumOfDuties()        const;
	int getCurrentNumOfDuties()    const;

	void setMaxNumOfDuties(int maxNumOfDuties);

	void addDuty(const char* duty);
	void removeDuty(const char* duty);

	void work() const override;
	virtual void toOs(std::ostream& os) const override;

	void operator+=(const char* duty);
	void operator-=(const char* duty);

protected:
	int maxNumOfDuties;
	int currentNumOfDuties;
	char** duties;
};

#endif // NURSE_H_INCLUDED
