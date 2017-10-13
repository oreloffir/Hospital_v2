#include "patient.h"


Patient::Patient(int id, const string& name, const string& dateOfBirth, eGender gender)
	: Person(id, name, dateOfBirth, gender)
{
	cout << "In Patient::Patient (name=" << this->name << ")" << endl;
}

Patient::~Patient()
{
	cout << "In Patient::~Patient (name=" << name << ")" << endl;
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
	if (visit == nullptr)
		return;
	visits.push_back(visit);
	setLastDateVisited(visit->getDate());
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
	if (nameOfAllergie.empty())
		return false;
	allergies.push_back(nameOfAllergie);
	return true;
}

int Patient::getNumOfVisits() const
{
	return (int)visits.size();
}
int Patient::getNumOfAllergies() const
{
	return (int)allergies.size();
}
const vector<const Visit*>  Patient::getVisits() const
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

	if (allergies.size() == 0)
		os << "\t" " No allergies." << endl;
	else {
		os << endl;
		vector<string>::const_iterator itr = allergies.begin();
		vector<string>::const_iterator itrEnd = allergies.end();
		for (; itr != itrEnd; itr++)
			os << "\t" << *itr << endl;
	}
	os << "---------------------------------------" << endl;
}
void Patient::printVisits() const
{
	cout << "================= " << getName() << " Visits History =================" << endl;
	vector<const Visit*>::const_iterator itr = visits.begin();
	vector<const Visit*>::const_iterator itrEnd = visits.end();
	for (; itr != itrEnd; itr++)
		cout << *(*itr) << endl;
}