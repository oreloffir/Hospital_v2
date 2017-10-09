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
	seeingStaff = new const CareGivingEmployee*[MAX_NUM_OF_SEEING_STAFF];
}
Visit::Visit(const Visit& other)
{
	*this = other;
	cout << "In Visit::Visit(copy) (cause=" << cause << ")" << endl;
}
Visit::~Visit()
{
	cout << "In Visit::~Visit (cause=" << cause << ")" << endl;
	this->free();
}

const Visit& Visit::operator=(const Visit& other)
{
	if (this != &other)
	{
		this->free();
		this->seeingStaff = new const CareGivingEmployee*[MAX_NUM_OF_SEEING_STAFF];
		this->date = other.date;
		this->cause = other.cause;
		this->department = other.department;
		this->patient = other.patient;
		this->currentNumOfSeeingStaff = other.currentNumOfSeeingStaff;
		this->typeOfCare = other.typeOfCare;
		for (int i = 0; i < other.currentNumOfSeeingStaff; i++)
		{
			this->seeingStaff[i] = other.seeingStaff[i];
		}
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
const CareGivingEmployee** Visit::getSeeingStaff() const
{
	return seeingStaff;
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
	return currentNumOfSeeingStaff;
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
	for (int i = 0; i < currentNumOfSeeingStaff; i++)
		if (seeingStaff[i]->getId() == careGivingEmployeeId)
			return seeingStaff[i];
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
	if (currentNumOfSeeingStaff == MAX_NUM_OF_SEEING_STAFF) return; // TODO: throw exeption!
	seeingStaff[currentNumOfSeeingStaff] = &employee;
	++currentNumOfSeeingStaff;
}
void Visit::removeSeeingStaff(int employeeId)
{
	int pos = -1;
	for (int i = 0; i < currentNumOfSeeingStaff; i++)
		if (seeingStaff[i]->getEmployeeId() == employeeId)
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == MAX_NUM_OF_SEEING_STAFF - 1)
	{
		seeingStaff[pos] = nullptr;
		--currentNumOfSeeingStaff;
		return;
	}
	for (int i = pos; i < this->currentNumOfSeeingStaff && i < MAX_NUM_OF_SEEING_STAFF - 1; i++)
		seeingStaff[i] = seeingStaff[i + 1];

	--currentNumOfSeeingStaff;
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

void Visit::free()
{
	delete[] seeingStaff;
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