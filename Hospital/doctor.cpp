#include "doctor.h"

#include <iostream>
using namespace std;

Doctor::Doctor(const Doctor& other)
	:Employee(other), CareGivingEmployee(other)
{
	*this = other;
}

const Doctor& Doctor::operator=(const Doctor& other)
{
	if (this != &other)
	{
		this->fieldOfExpertise = other.fieldOfExpertise;
		this->numOfDiplomas = other.numOfDiplomas;
	}
	return *this;
}

int Doctor::getNumOfDiplomas() const
{
	return numOfDiplomas;
}
const string& Doctor::getFieldOfExpertise() const
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
const Doctor& Doctor::operator++()
{
	this->addDiploma();
	return *this;
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
