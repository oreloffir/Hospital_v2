#ifndef NURSE_H_INCLUDED
#define NURSE_H_INCLUDED

#include "careGivingEmployee.h"
#include "LinkedList.h"
#include <string>
using namespace std;

class Nurse : public CareGivingEmployee
{

public:
	Nurse(CareGivingEmployee& CGEmployee, int maxNumOfDuties)
		: Employee(CGEmployee),
		CareGivingEmployee(CGEmployee),
		maxNumOfDuties(maxNumOfDuties) {};
	
	Nurse(const Nurse& other)				= delete;
	Nurse& operator=(const Nurse& other)	= delete;

	const LinkedList<string>& getDuties()	const;
	int getCurrentNumOfDuties()				const;

	void addDuty(const string& duty);
	void removeDuty(const string& duty);
	void setMaxNumOfDuties(int maxNumOfDuties);

	void work() const override;
	virtual void toOs(std::ostream& os) const override;

	void operator+=(const string& duty);
	void operator-=(const string& duty);

private:
	int maxNumOfDuties;
	LinkedList<string> dutiesList;
};
#endif // NURSE_H_INCLUDED
