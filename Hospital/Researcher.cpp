#include "researcher.h"


Researcher::Researcher(int id, const char* name, const char* dateOfBirth, eGender gender,
	const char* startWorkingDate, eRank employeeRank, double salary,
	const char* areaOfTraining, float seniorityYears, const char* areaOfResearch)
	:Employee(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->numOfPublications = 0;
	this->areaOfResearch = _strdup(areaOfResearch);
	this->publicationsNames = new char*[MAX_NUMBER_OF_PUBLICATIONS];
}
Researcher::Researcher(const Employee& employee, const char* areaOfResearch)
	:Employee(employee)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->numOfPublications = 0;
	this->areaOfResearch = _strdup(areaOfResearch);
	this->publicationsNames = new char*[MAX_NUMBER_OF_PUBLICATIONS];
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
		this->areaOfResearch = _strdup(other.areaOfResearch);
		this->publicationsNames = new char*[MAX_NUMBER_OF_PUBLICATIONS];
		for (int i = 0; i < other.numOfPublications; i++)
			publicationsNames[i] = _strdup(other.publicationsNames[i]);
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
	delete[] areaOfResearch;
	for (int i = 0; i < numOfPublications; i++)
		delete[] publicationsNames[i];
	delete[] publicationsNames;
}

int Researcher::getNumOfPublications() const
{
	return numOfPublications;
}
const char* const Researcher::getAreaOfResearch() const
{
	return areaOfResearch;
}
const char* const* Researcher::getPublicationsNames() const {
	return publicationsNames;
}
bool Researcher::addPublicationName(const char * publicationName)
{
	if (numOfPublications == MAX_NUMBER_OF_PUBLICATIONS) return false;
	this->publicationsNames[numOfPublications] = _strdup(publicationName);
	++numOfPublications;
	return true;
}
void Researcher::operator+=(const char* publication) {
	publicationsNames[numOfPublications] = _strdup(publication);
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