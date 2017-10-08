#include "doctor.h"
#include <iostream>
using namespace std;



Doctor::Doctor(CareGivingEmployee& CGEmployee, const char* fieldOfExpertise, int numOfDiplomas)
	: Employee(CGEmployee),
	CareGivingEmployee(CGEmployee)
{
	std::cout << "In Doctor::Doctor()" << "---->" << this->name << std::endl;
	this->numOfDiplomas = numOfDiplomas;
	this->fieldOfExpertise = _strdup(fieldOfExpertise);
}
Doctor::Doctor(const Doctor& other)
	:Employee(other), CareGivingEmployee(other)
{
	std::cout << "In Doctor::Doctor(copy)" << "---->" << this->name << std::endl;
	*this = other;
}

const Doctor& Doctor::operator=(const Doctor& other)
{
	if (this != &other)
	{
		this->free();
		this->fieldOfExpertise = _strdup(other.fieldOfExpertise);
		this->numOfDiplomas = other.numOfDiplomas;
	}
	return *this;
}
Doctor::~Doctor()
{
	std::cout << "In Doctor::~Doctor()" << "---->" << this->name << std::endl;
	this->free();
}
int Doctor::getNumOfDiplomas() const
{
	return numOfDiplomas;
}
const char* Doctor::getFieldOfExpertise() const
{
	return fieldOfExpertise;
}
void Doctor::setNumOfDiplomas(int numOfDiplomas)
{
	this->numOfDiplomas = numOfDiplomas;
}
void Doctor::addDiploma()
{
	this->setNumOfDiplomas(++numOfDiplomas);
}
void Doctor::free()
{
	delete[] fieldOfExpertise;
}
void Doctor::work() const
{
	std::cout << "I'm a Doctor " << name << " and I'm working" << std::endl;
}

void Doctor::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "-----------Doctor Details-----------" << endl;
	os << "Number Of Diplomas: " << numOfDiplomas << endl;
	os << "Field Of Expertise: " << fieldOfExpertise << endl;
}
