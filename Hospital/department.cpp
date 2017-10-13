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
	return (int)allPatients.size();
}
int Department::getCurrentNumOfEmployees() const
{
	return (int)allEmployees.size();
}
int Department::getCurrentNumOfVisits() const
{
	return (int)allVisits.size();
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
	// check if we have pointer to this Patient already (by Id)
	if (getPatientById(newPatient->getId()) != nullptr)
		return;

	allPatients.push_back(newPatient);
}
void Department::addEmployee(const Employee* newEmployee)
{
	// check if we have pointer to this employee already (by Id)
	if (getEmployeeById(newEmployee->getId()) != nullptr)
		return;
	allEmployees.push_back(newEmployee);
}
void Department::addVisit(const Visit* visit)
{
	// check if we have pointer to this visit already (by Id)
	if (getVisitById(visit->getVisitId()) != nullptr)
		return;
	allVisits.push_back(visit);
}

void Department::removePatientById(int id)
{
	bool found = false;
	vector<const Patient*>::const_iterator itr = allPatients.begin();
	vector<const Patient*>::const_iterator itrEnd = allPatients.end();
	for (itr ; itr != itrEnd ; itr++)
		if ((*itr)->getId() == id)
		{
			found = true;
			break;
		}
	if (!found) return;
	allPatients.erase(itr);
}
void Department::removeEmployeeById(int employeeId)
{
	bool found = false;
	vector<const Employee*>::const_iterator itr = allEmployees.begin();
	vector<const Employee*>::const_iterator itrEnd = allEmployees.end();
	for (itr; itr != itrEnd; itr++)
		if ((*itr)->getEmployeeId() == employeeId)
		{
			found = true;
			break;
		}
	if (!found) return;
	allEmployees.erase(itr);
}
void Department::removeVisitById(int visitId)
{
	bool found = false;
	vector<const Visit*>::const_iterator itr = allVisits.begin();
	vector<const Visit*>::const_iterator itrEnd = allVisits.end();
	for (itr; itr != itrEnd; itr++)
		if ((*itr)->getVisitId() == visitId)
		{
			found = true;
			break;
		}
	if (!found) return;
	allVisits.erase(itr);
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
bool Department::operator==(const Department& other)
{
	return (this->name == other.getName()) ? true : false;
}

void Department::onEmployeeRemoved(int employeeId)
{
	removeEmployeeById(employeeId);
}
void Department::onEmployeeReplaced(const Employee* newPointer)
{
	if (newPointer != nullptr && getEmployeeByEmployeeId(newPointer->getEmployeeId()) != nullptr)
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