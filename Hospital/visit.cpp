#include "visit.h"
#include <iostream>
using namespace std;

Visit::Visit(const string& date, const string& cause, const Department* department, const Patient* patient, eCare typeOfCare)
	:	department(department),
		patient(patient),
		typeOfCare(typeOfCare),
		date(date),
		cause(cause)
{
	cout << "In Visit::Visit (cause=" << cause << ")" << endl;
	visitId = visitIdGenerator;
	++visitIdGenerator;
}
Visit::Visit(const Visit& other)
{
	*this = other;
	cout << "In Visit::Visit(copy) (cause=" << cause << ")" << endl;
}
Visit::~Visit()
{
	cout << "In Visit::~Visit (cause=" << cause << ")" << endl;
}

const Visit& Visit::operator=(const Visit& other)
{
	if (this != &other)
	{
		this->seeingStaff = other.seeingStaff;
		this->date = other.date;
		this->cause = other.cause;
		this->department = other.department;
		this->patient = other.patient;
		this->typeOfCare = other.typeOfCare;
	}
	return *this;
}

const string& Visit::getDate() const
{
	return date;
}
const string& Visit::getCause() const
{
	return cause;
}
const Department* Visit::getDepratment() const
{
	return department;
}
const Patient* Visit::getPatient() const
{
	return patient;
}
const vector<const CareGivingEmployee*> Visit::getSeeingStaff() const
{
	return seeingStaff;
}
void Visit::printSeeingStaff() const
{
	if (seeingStaff.size() == 0)
		cout << "No care giving employees set yet." << endl;
	else {
		vector<const CareGivingEmployee*>::const_iterator itr = seeingStaff.begin();
		vector<const CareGivingEmployee*>::const_iterator itrEnd = seeingStaff.end();
		for (; itr != itrEnd; itr++)
			cout << *(*itr) << endl;
	}
}
Visit::eCare Visit::getTypeOfCare() const
{
	return typeOfCare;
}
int Visit::getMaxNumOfSeeingStaff() const
{
	return MAX_NUM_OF_SEEING_STAFF;
}
int Visit::getCurrentNumOfSeeingStaff() const
{
	return (int)seeingStaff.size();
}
int Visit::getVisitId() const
{
	return visitId;
}
const string& Visit::getTypeOfCareName() const
{
	return Visit::cares[typeOfCare];
}
const CareGivingEmployee* Visit::getCareGivingEmployeeById(int careGivingEmployeeId) const
{
	vector<const CareGivingEmployee*>::const_iterator itr = seeingStaff.begin();
	vector<const CareGivingEmployee*>::const_iterator itrEnd = seeingStaff.end();
	for (; itr != itrEnd && *itr != NULL; itr++)
		if ((*itr)->getId() == careGivingEmployeeId)
			return *itr;
	return nullptr;
}

void Visit::setCause(const string& cause)
{
		this->cause = cause;
}
void Visit::setTypeOfCare(eCare typeOfCare)
{
	this->typeOfCare = typeOfCare;
}
void Visit::addSeeingStaff(const CareGivingEmployee& employee)
{
	// check if we have pointer to this employee already (by Id)
	if (getCareGivingEmployeeById(employee.getEmployeeId()) != nullptr)
		return;
	seeingStaff.push_back(&employee);
}
void Visit::removeSeeingStaff(int employeeId)
{
	bool found = false;
	vector<const CareGivingEmployee*>::const_iterator itr = seeingStaff.begin();
	vector<const CareGivingEmployee*>::const_iterator itrEnd = seeingStaff.end();
	for (itr; itr != itrEnd; itr++)
		if ((*itr)->getEmployeeId() == employeeId)
		{
			found = true;
			break;
		}
	if (!found) return;
	seeingStaff.erase(itr);
}

void Visit::operator+=(const CareGivingEmployee& cgEmployee)
{
	addSeeingStaff(cgEmployee);
}
void Visit::operator-=(const CareGivingEmployee& cgEmployee)
{
	removeSeeingStaff(cgEmployee.getEmployeeId());
}

void Visit::rescheduleVisit(const string& newDate)
{
	date = newDate;
}
void Visit::changeDepartment(const Department &other)
{
	department = &other;
}

void Visit::onEmployeeRemoved(int employeeId)
{
	removeSeeingStaff(employeeId);
}
void Visit::onEmployeeReplaced(const Employee* newPointer)
{
	const CareGivingEmployee* cge = dynamic_cast<const CareGivingEmployee*>(newPointer);
	if (cge != nullptr)
	{
		*this -= *cge;
		*this += *cge;
	}
}

std::ostream& operator<<(std::ostream& os, const Visit& visit)
{
	os << "--------------Visit no." << visit.getVisitId() << " Details-------------" << endl;
	os << "Date: " << "\t\t\t\t" << visit.getDate() << endl;
	os << "Cause: " << "\t\t\t\t" << visit.getCause() << endl;
	os << "Department name: " << "\t\t" << visit.getDepratment()->getName() << endl;
	os << "Patient name: " << "\t\t\t" << visit.getPatient()->getName() << endl;
	os << "Number of seeing stuff: " << "\t" << visit.getCurrentNumOfSeeingStaff() << endl;
	os << "Type of care: " << "\t\t\t" << visit.getTypeOfCareName() << endl;
	visit.toOs(os);
	return os;
}

const string Visit::cares[] = { "FIRST_AID", "TESTS", "SURGERY_PREP", "SURGERY" };
int Visit::visitIdGenerator = 1;