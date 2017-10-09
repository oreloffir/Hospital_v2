#include "patient.h"


Patient::Patient(int id, const string& name, const string& dateOfBirth, eGender gender)
	: Person(id, name, dateOfBirth, gender)
{
	allergies				= new string[Patient::MAX_NUMBER_OF_ALLERGIES];
	visits					= new const Visit*[Patient::MAX_NUMBER_OF_VISITS];
	numOfAllergies			= 0;
	numOfVisits				= 0;
	cout << "In Patient::Patient (name=" << this->name << ")" << endl;
}

Patient::~Patient()
{
	cout << "In Patient::~Patient (name=" << name << ")" << endl;
	delete[] allergies;
	delete[] visits;
}

void Patient::visitHospital(const string& date)
{
	lastDateVisited = date;
}

bool Patient::anesthetize(const string& date)
{
	lastDateAnesthetized = date;
	return true;
}

void Patient::addVisit(const Visit* visit)
{
	if (numOfVisits == MAX_NUMBER_OF_VISITS) return; //TODO: expection
	visits[numOfVisits] = visit;
	setLastDateVisited(visit->getDate());
	++numOfVisits;
}

void Patient::setLastDateVisited(const string& lastDateVisited)
{
	this->lastDateVisited = lastDateVisited;
}

void Patient::setLastDateAnesthetized(const string& lastDateAnesthetized)
{
	this->lastDateAnesthetized = lastDateAnesthetized;
}

bool Patient::addAllergie(const string& nameOfAllergie)
{
	if (numOfAllergies == MAX_NUMBER_OF_ALLERGIES) return false;
	this->allergies[numOfAllergies] = nameOfAllergie;
	++numOfAllergies;
	return true;
}

int Patient::getNumOfVisits() const
{
	return numOfVisits;
}

int Patient::getNumOfAllergies() const
{
	return numOfAllergies;
}

const Visit* const* Patient::getVisits() const
{
	return visits;
}

const string& Patient::getLastDateVisited() const
{
	return lastDateVisited;
}

const string& Patient::getLastDateAnesthetized() const
{
	return lastDateAnesthetized;
}

void Patient::toOs(ostream& os) const
{
	os << "-----------Patient Details-----------" << endl;
	os << "Number Of Allergies: " << "\t" << this->getNumOfAllergies() << endl;
	os << "Number Of Visits: " << "\t" << this->getNumOfVisits() << endl;
	if (this->getNumOfVisits() != 0)
		os << "Last Date Visited: " << "\t" << this->getLastDateVisited() << endl;
	if(!(this->getLastDateAnesthetized().empty()))
		os << "Last Date Anesthetized: " << "\t" << this->getLastDateAnesthetized() << endl;
	else
	{
		os << "Patient didn't anesthetized yet." << endl;
	}
	os << "Patient Allergies: ";

	if (numOfAllergies == 0)
		os << "\t" " No allergies." << endl;
	else {
		os << endl;
		for (int i = 0; i < numOfAllergies; i++)
			os << "\t" << allergies[i] << endl;
	}
	os << "---------------------------------------" << endl;
}

void Patient::printVisits() const
{
	cout << "================= " << getName() << " Visits History =================" << endl;
	for (int i = 0; i < numOfVisits; i++)
		cout << *visits[i] << endl;
}