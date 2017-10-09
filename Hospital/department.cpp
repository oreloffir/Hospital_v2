#pragma once
#include "department.h"
#include "patient.h"
#include "employee.h"
#include <string>
#include <iostream>
using namespace std;

Department::Department(const string& name)
	:name(name)
{
	cout << "In Department::Department (name=" << name << ")" << endl;
	currentNumOfPatients	= 0;
	currentNumOfEmployees	= 0;
	currentNumOfVisits		= 0;
}

Department::~Department()
{
	cout << "In Department::~Department (name=" << name << ")" << endl;
}

const string& Department::getName() const
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
const vector<const Patient*> Department::getAllPatients() const
{
	return allPatients;
}
const vector<const Visit*> Department::getAllVisits() const
{
	return allVisits;
}
const vector<const Employee*> Department::getAllEmployees() const
{
	return allEmployees;
}
const Patient* Department::getPatientById(int id) const
{
	vector<const Patient*>::const_iterator itr = allPatients.begin();
	vector<const Patient*>::const_iterator itrEnd = allPatients.end();
	for ( ; itr != itrEnd && *itr != NULL; itr++ )
		if ((*itr)->getId() == id )
			return *itr;
	return nullptr;
}
const Visit* Department::getVisitById(int id) const
{
	vector<const Visit*>::const_iterator itr = allVisits.begin();
	vector<const Visit*>::const_iterator itrEnd = allVisits.end();
	for (; itr != itrEnd && *itr != NULL; itr++)
		if ((*itr)->getVisitId() == id)
			return *itr;
	return nullptr;
	
}
const Employee* Department::getEmployeeById(int id) const
{
	vector<const Employee*>::const_iterator itr = allEmployees.begin();
	vector<const Employee*>::const_iterator itrEnd = allEmployees.end();
	for (; itr != itrEnd && *itr != NULL ; itr++)
		if ((*itr)->getId() == id)
			return *itr;
	return nullptr;
}
const Employee* Department::getEmployeeByEmployeeId(int employeeId) const
{
	vector<const Employee*>::const_iterator itr = allEmployees.begin();
	vector<const Employee*>::const_iterator itrEnd = allEmployees.end();
	for (; itr != itrEnd; itr++)
		if ((*itr)->getEmployeeId() == employeeId)
			return *itr;
	return nullptr;
}

void Department::setName(const string& name) 
{
	this->name = name;
}
void Department::addPatient(const Patient* newPatient)
{
	// check if we have pointer to this employee already (by Id)
	if (getPatientById(newPatient->getId()) != nullptr)
		return;

	allPatients.push_back(newPatient);
	++currentNumOfPatients;
	/*if (currentNumOfPatients == MAX_NUMBER_OF_PATIENTS) return; // TODO: throw exception
	allPatients[currentNumOfPatients] = newPatient;*/
	
}
void Department::addEmployee(const Employee* newEmployee)
{
	// check if we have pointer to this employee already (by Id)
	if (getEmployeeById(newEmployee->getId()) != nullptr)
		return;
	allEmployees.push_back(newEmployee);
	++currentNumOfEmployees;
}
void Department::removePatientById(int id)
{
	int pos = -1;
	vector<const Patient*>::const_iterator itr = allPatients.begin();
	vector<const Patient*>::const_iterator itrEnd = allPatients.end();
	for (int i=0 ; itr != itrEnd ; itr++, i++)
		if ((*itr)->getId() == id)
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
	if (allPatients.capacity() <= currentNumOfPatients)
		allPatients.resize(currentNumOfPatients * 2);
	for (int i = pos; i < currentNumOfPatients ; i++)
		allPatients[i] = allPatients[i + 1];
	--currentNumOfPatients;
}
void Department::removeEmployeeById(int employeeId)
{
	int pos = -1;
	vector<const Employee*>::const_iterator itr = allEmployees.begin();
	vector<const Employee*>::const_iterator itrEnd = allEmployees.end();
	for (int i = 0; itr != itrEnd; itr++, i++)
		if ((*itr)->getEmployeeId() == employeeId)
		{
			pos = i;
			break;
		}
		
	if (pos < 0) return;
	if (pos == currentNumOfEmployees - 1)
	{
		allEmployees[pos] = nullptr;
		--currentNumOfEmployees;
		return;
	}
	if (allEmployees.capacity() <= currentNumOfEmployees)
		allEmployees.resize(currentNumOfEmployees * 2);
	for (int i = pos; i < currentNumOfEmployees ; i++) 
		allEmployees[i] = allEmployees[i + 1];
	--currentNumOfEmployees;
}
void Department::addVisit(const Visit* visit)
{
	// check if we have pointer to this employee already (by Id)
	if (getVisitById(visit->getVisitId()) != nullptr)
		return;
	allVisits.push_back(visit);
	++currentNumOfVisits;
}
void Department::removeVisitById(int visitId)
{
	int pos = -1;
	vector<const Visit*>::const_iterator itr = allVisits.begin();
	vector<const Visit*>::const_iterator itrEnd = allVisits.end();
	for (int i = 0; itr != itrEnd; itr++, i++)
		if ((*itr)->getVisitId() == visitId)
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
	if (allVisits.capacity() <= currentNumOfVisits)
		allVisits.resize(currentNumOfVisits * 2);
	for (int i = pos; i < this->currentNumOfVisits ; i++)
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