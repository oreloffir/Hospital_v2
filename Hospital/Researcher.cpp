#include "researcher.h"


Researcher::Researcher(int id, const string& name, const string& dateOfBirth, eGender gender,
	const string& startWorkingDate, eRank employeeRank, double salary,
	const string& areaOfTraining, float seniorityYears, const string& areaOfResearch)
	:Employee(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->numOfPublications = 0;
	this->areaOfResearch = areaOfResearch;
	this->publicationsNames = new string[MAX_NUMBER_OF_PUBLICATIONS];
}
Researcher::Researcher(const Employee& employee, const string& areaOfResearch)
	:Employee(employee)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->numOfPublications = 0;
	this->areaOfResearch = areaOfResearch;
	this->publicationsNames = new string[MAX_NUMBER_OF_PUBLICATIONS];
}
Researcher::Researcher(const Researcher& other)
	: Employee(other)
{
	cout << "In Researcher::Researcher(copy)" << "---->" << this->name << endl;
	*this = other;
}
const Researcher& Researcher::operator=(const Researcher& other)
{
	cout << "In Researcher::operator=()" << "---->" << this->name << endl;
	if (this != &other)
	{
		this->free();
		this->numOfPublications = other.numOfPublications;
		this->areaOfResearch = other.areaOfResearch;
		this->publicationsNames = new string[MAX_NUMBER_OF_PUBLICATIONS];
		for (int i = 0; i < other.numOfPublications; i++)
			publicationsNames[i] = other.publicationsNames[i];
	}
	return *this;
}
Researcher::~Researcher()
{
	cout << "In Researcher::~Researcher()" << "---->" << this->name << endl;
	this->free();
}

void Researcher::free()
{
	delete[] publicationsNames;
}

int Researcher::getNumOfPublications() const
{
	return numOfPublications;
}
const string& const Researcher::getAreaOfResearch() const
{
	return areaOfResearch;
}
const string* Researcher::getPublicationsNames() const 
{
	return publicationsNames;
}
bool Researcher::addPublicationName(const string publicationName)
{
	if (numOfPublications == MAX_NUMBER_OF_PUBLICATIONS) return false;
	this->publicationsNames[numOfPublications] = publicationName;
	++numOfPublications;
	return true;
}
void Researcher::operator+=(const string publication) 
{
	publicationsNames[numOfPublications] = publication;
	++numOfPublications;
}
void Researcher::work() const
{
	cout << "Researcher " << name << " WORKING!" << endl;
}
void Researcher::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "-----------Researcher Details-----------" << endl;
	os << "Area Of Research: " << this->getAreaOfResearch() << endl;
}