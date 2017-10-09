#include "nurse.h"
#include <iostream>

Nurse::Nurse(CareGivingEmployee& CGEmployee, int maxNumOfDuties)
	: Employee(CGEmployee),
	CareGivingEmployee(CGEmployee)
{
	std::cout << "In Nurse::Nurse()" << "---->" << this->name << std::endl;
}
Nurse::~Nurse()
{
	std::cout << "In Nurse::~Nurse()" << "---->" << this->name << std::endl;
}
const LinkedList<string>& Nurse::getDuties() const
{
	return dutiesList;
}
int Nurse::getCurrentNumOfDuties() const
{
	return dutiesList.getSize();
}

void Nurse::addDuty(const string duty)
{
	dutiesList.insertToTail(string(duty));
}

void Nurse::removeDuty(const string duty)
{
	dutiesList.remove(duty);
}

void Nurse::operator+=(const string duty)
{
	this->addDuty(duty);
}

void Nurse::operator-=(const string duty)
{
	this->removeDuty(duty);
}

void Nurse::work() const
{
	std::cout << "I'm a nurse " << name << " and I'm working" << std::endl;
}

void Nurse::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "-----------Nurse Details-----------" << endl;
	os << "Num Of Duties: ";

	if (dutiesList.getSize() == 0)
		os << " No Duties." << endl;
	else {
		os << dutiesList.getSize() << endl;
		os << dutiesList;
	}
	os << "---------------------------------------" << endl;

}