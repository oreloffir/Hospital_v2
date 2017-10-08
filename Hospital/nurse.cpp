#include "nurse.h"
#include <iostream>

Nurse::Nurse(CareGivingEmployee& CGEmployee, int maxNumOfDuties)
	: Employee(CGEmployee),
	CareGivingEmployee(CGEmployee)
{
	std::cout << "In Nurse::Nurse()" << "---->" << this->name << std::endl;
	this->currentNumOfDuties = 0;
	this->maxNumOfDuties = maxNumOfDuties;
	this->duties = new char*[maxNumOfDuties];
}
Nurse::~Nurse()
{
	std::cout << "In Nurse::~Nurse()" << "---->" << this->name << std::endl;
	for (int i = 0; i < currentNumOfDuties; i++)
		delete duties[i];
	delete[] duties;
}
const char* const* Nurse::getDuties() const
{
	return duties;
}
int Nurse::getMaxNumOfDuties() const
{
	return maxNumOfDuties;
}
int Nurse::getCurrentNumOfDuties() const
{
	return currentNumOfDuties;
}
void Nurse::setMaxNumOfDuties(int maxNumOfDuties)
{
	char** newDuties = new char*[maxNumOfDuties];
	for (int i = 0; i < this->currentNumOfDuties; i++)
		newDuties[i] = duties[i];

	this->maxNumOfDuties = maxNumOfDuties;
	delete[] duties;
	this->duties = newDuties;
}

void Nurse::addDuty(const char* duty)
{
	if (currentNumOfDuties == maxNumOfDuties) return; // TODO: throw exeption!
	duties[currentNumOfDuties] = _strdup(duty);
	++currentNumOfDuties;
}

void Nurse::removeDuty(const char* duty)
{
	int pos = -1;
	for (int i = 0; i < this->currentNumOfDuties; i++)
		if (strcmp(duties[i], duty) == 0)
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == maxNumOfDuties - 1)
	{
		duties[pos] = nullptr;
		--currentNumOfDuties;
		return;
	}
	for (int i = pos; i < this->currentNumOfDuties && i < maxNumOfDuties - 1; i++)
		duties[i] = duties[i + 1];
	--currentNumOfDuties;
}

void Nurse::operator+=(const char* duty)
{
	this->addDuty(duty);
}

void Nurse::operator-=(const char* duty)
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

	if (currentNumOfDuties == 0)
		os << " No Duties." << endl;
	else {
		os << currentNumOfDuties << endl;
		for (int i = 0; i < currentNumOfDuties; i++)
			os << "\t" << duties[i] << endl;
	}
	os << "---------------------------------------" << endl;

}