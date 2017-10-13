#include "researcher.h"


Researcher::Researcher(int id, const string& name, const string& dateOfBirth, eGender gender,
	const string& startWorkingDate, eRank employeeRank, double salary,
	const string& areaOfTraining, float seniorityYears, const string& areaOfResearch)
	:Employee(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
	this->areaOfResearch = areaOfResearch;
}
Researcher::Researcher(const Employee& employee, const string& areaOfResearch)
	:Employee(employee)
{
	cout << "In Researcher::Researcher" << "---->" << this->name << endl;
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
		this->areaOfResearch	= other.areaOfResearch;
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
	return (int)publicationsNames.size();
}
const string& const Researcher::getAreaOfResearch() const
{
	return areaOfResearch;
}
const vector<string> Researcher::getPublicationsNames() const 
{
	return publicationsNames;
}
bool Researcher::addPublicationName(const string publicationName)
{
	this->publicationsNames.push_back(publicationName);
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
	os << "Publications Names: ";
	if (publicationsNames.size() == 0)
		os << "No Publications Names" << endl;
	else
	{
		os << endl;
		for (vector<string>::const_iterator itr = publicationsNames.begin();
			itr < publicationsNames.end(); itr++)
			os << *itr << endl;
	}
		
}