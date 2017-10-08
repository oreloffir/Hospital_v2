#pragma once
#include "department.h"
#include "patient.h"
#include "employee.h"
#include <iostream>
using namespace std;

Department::Department(const char* name)
{
	cout << "In Department::Department (name=" << name << ")" << endl;
	this->name = _strdup(name);
	currentNumOfPatients	= 0;
	currentNumOfEmployees	= 0;
	currentNumOfVisits		= 0;
	allPatients	 = new const Patient*[MAX_NUMBER_OF_PATIENTS];
	allEmployees = new const Employee*[MAX_NUMBER_OF_EMPLOYEES];
	allVisits	 = new const Visit*[MAX_NUMBER_OF_VISITS];
}

Department::~Department()
{
	cout << "In Department::~Department (name=" << name << ")" << endl;
	delete[] name;
	delete[] allPatients;
	delete[] allEmployees;
}

const char* Department::getName() const
{
	return name;
}
int Department::getCurrentNumOfPatients() const
{
	return currentNumOfPatients;
}
int Department::getCurrentNumOfEmployees() const
{
	return currentNumOfEmployees;
}
int Department::getCurrentNumOfVisits() const
{
	return currentNumOfVisits;
}
const Patient* const* Department::getAllPatients() const
{
	return allPatients;
}
const Visit* const* Department::getAllVisits() const
{
	return allVisits;
}
const Employee* const* Department::getAllEmployees() const
{
	return allEmployees;
}
const Patient* Department::getPatientById(int id) const
{
	for (int i = 0; i < currentNumOfPatients; i++)
		if (allPatients[i]->getId() == id)
			return allPatients[i];
	return nullptr;
}
const Visit* Department::getVisitById(int id) const
{
	for (int i = 0; i < currentNumOfVisits; i++)
		if (allVisits[i]->getVisitId() == id)
			return allVisits[i];
	return nullptr;
}
const Employee* Department::getEmployeeById(int id) const
{
	for (int i = 0; i < currentNumOfEmployees; i++)
		if (allEmployees[i]->getId() == id)
			return allEmployees[i];
	return nullptr;
}
const Employee* Department::getEmployeeByEmployeeId(int employeeId) const
{
	for (int i = 0; i < currentNumOfEmployees; i++)
		if (allEmployees[i]->getEmployeeId() == employeeId)
			return allEmployees[i];
	return nullptr;
}

void Department::setName(const char* name) 
{
	delete[] name;
	name = _strdup(name);
}
void Department::addPatient(const Patient* newPatient)
{
	// check if we have pointer to this employee already (by Id)
	if (getPatientById(newPatient->getId()) != nullptr)
		return;
	if (currentNumOfPatients == MAX_NUMBER_OF_PATIENTS) return; // TODO: throw exception
	allPatients[currentNumOfPatients] = newPatient;
	++currentNumOfPatients;
}
void Department::addEmployee(const Employee* newEmployee)
{
	// check if we have pointer to this employee already (by Id)
	if (getEmployeeById(newEmployee->getId()) != nullptr)
		return;
	if (currentNumOfEmployees == MAX_NUMBER_OF_EMPLOYEES) return; // TODO: throw exception
	allEmployees[currentNumOfEmployees] = newEmployee;
	++currentNumOfEmployees;
}
void Department::removePatientById(int id)
{
	int pos = -1;
	for (int i = 0; i < currentNumOfPatients; i++)
		if (allPatients[i]->getId() == id)
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == currentNumOfPatients - 1)
	{
		allPatients[pos] = nullptr;
		--currentNumOfPatients;
		return;
	}
	for (int i = pos; i < currentNumOfPatients && i < MAX_NUMBER_OF_PATIENTS - 1; i++)
		allPatients[i] = allPatients[i + 1];
	--currentNumOfPatients;
}
void Department::removeEmployeeById(int employeeId)
{
	int pos = -1;
	for (int i = 0; i < currentNumOfEmployees; i++)
		if (allEmployees[i]->getEmployeeId() == employeeId)
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == currentNumOfPatients - 1)
	{
		allEmployees[pos] = nullptr;
		--currentNumOfEmployees;
		return;
	}
	for (int i = pos; i < currentNumOfEmployees && i < MAX_NUMBER_OF_EMPLOYEES - 1; i++)
		allEmployees[i] = allEmployees[i + 1];
	--currentNumOfEmployees;
}
void Department::addVisit(const Visit* visit)
{
	// check if we have pointer to this employee already (by Id)
	if (getVisitById(visit->getVisitId()) != nullptr)
		return;
	if (currentNumOfVisits == MAX_NUMBER_OF_VISITS) return; // TODO: throw exception
	allVisits[currentNumOfVisits] = visit;
	++currentNumOfVisits;
}
void Department::removeVisitById(int visitId)
{
	int pos = -1;
	for (int i = 0; i < this->currentNumOfVisits; i++)
		if (visitId == allVisits[i]->getVisitId())
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == MAX_NUMBER_OF_VISITS - 1)
	{
		allVisits[pos] = nullptr;
		--currentNumOfVisits;
		return;
	}
	for (int i = pos; i < this->currentNumOfVisits && i < MAX_NUMBER_OF_VISITS - 1; i++)
		allVisits[i] = allVisits[i + 1];

	--currentNumOfVisits;
}

void Department::operator+=(const Employee& newEmployee)
{
	this->addEmployee(&newEmployee);
}
void Department::operator+=(const Patient& newPatient)
{
	this->addPatient(&newPatient);
}
void Department::operator+=(const Visit& newVisit)
{
	this->addVisit(&newVisit);
}
void Department::operator-=(const Employee& existingEmployee)
{
	this->removeEmployeeById(existingEmployee.getEmployeeId());
}
void Department::operator-=(const Patient& existingPatient)
{
	this->removePatientById(existingPatient.getId());
}
void Department::operator-=(const Visit& existingVisit)
{
	this->removeVisitById(existingVisit.getVisitId());
}

void Department::onEmployeeRemoved(int employeeId)
{
	removeEmployeeById(employeeId);
}
void Department::onEmployeeReplaced(const Employee* newPointer)
{
	if (newPointer != nullptr)
	{
		*this -= *newPointer;
		*this += *newPointer;
	}
}

ostream& operator<<(ostream& os, const Department& department)
{
	os << "----------------------------------" << endl;
	os << "Department Name: " << department.getName() << endl;
	os << "----------------------------------" << endl;
	os << "Current Number Of Patients: " << department.getCurrentNumOfPatients() << endl;
	os << "Current Number Of Employees: " << department.getCurrentNumOfEmployees() << endl;
	os << "Current Number Of Visits: " << department.getCurrentNumOfVisits() << endl;
	os << "----------------------------------" << endl;
	return os;
}