#include "researcher.h"


Researcher::Researcher(int id, const string& name, const string& dateOfBirth, eGender gender,
	const string& startWorkingDate, eRank employeeRank, double salary,
	const string& areaOfTraining, float seniorityYears, const string& areaOfResearch)
	:Employee(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->numOfPublications = 0;
	this->areaOfResearch = areaOfResearch;
}
Researcher::Researcher(const Employee& employee, const string& areaOfResearch)
	:Employee(employee)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->numOfPublications = 0;
	this->areaOfResearch = areaOfResearch;
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
		this->numOfPublications = other.numOfPublications;
		this->areaOfResearch = other.areaOfResearch;
		this->publicationsNames = other.publicationsNames;
	}
	return *this;
}
Researcher::~Researcher()
{
	cout << "In Researcher::~Researcher()" << "---->" << this->name << endl;

}

int Researcher::getNumOfPublications() const
{
	return numOfPublications;
}
const string& const Researcher::getAreaOfResearch() const
{
	return areaOfResearch;
}
const vector<string> Researcher::getPublicationsNames() const 
{
	return publicationsNames;
}
void Researcher::printPublicationsNames() const
{
	cout << "================= " << name << " publication names =================" << endl;
	if (numOfPublications == 0)
		cout << "\t - Researcher has no publications yet." << endl;
	else {
		vector<string>::const_iterator itr = publicationsNames.begin();
		vector<string>::const_iterator itrEnd = publicationsNames.end();
		for (; itr != itrEnd; itr++)
			cout << "\t - " << *(itr) << endl;
	}
}
bool Researcher::addPublicationName(const string publicationName)
{
	this->publicationsNames.push_back(publicationName);
	++numOfPublications;
	return true;
}
void Researcher::operator+=(const string publication) 
{
	addPublicationName(publication);
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