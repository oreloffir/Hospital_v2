#include "researcher.h"

Researcher::Researcher(const Researcher& other)
	: Employee(other)
{
	*this = other;
}
const Researcher& Researcher::operator=(const Researcher& other)
{
	if (this != &other)
	{
		this->areaOfResearch	= other.areaOfResearch;
		this->publicationsNames = other.publicationsNames;
	}
	return *this;
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
	if (getNumOfPublications() == 0)
		os << "No Publications Names" << endl;
	else
	{
		cout << getNumOfPublications() << endl;
		for (vector<string>::const_iterator itr = publicationsNames.begin();
			itr < publicationsNames.end(); itr++)
			os << *itr << endl;
	}
		
}
