#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "EmployeeListener.h"

class Patient;
class Employee;
class Visit;

class Department : public EmployeeListener
{
private:
    string name;
    vector<Patient const*> allPatients;
	vector<Employee const*> allEmployees;
	vector<Visit const*> allVisits;
public:
	static constexpr int MAX_NUMBER_OF_PATIENTS		= 200;
	static constexpr int MAX_NUMBER_OF_EMPLOYEES	= 20;
	static constexpr int MAX_NUMBER_OF_VISITS		= 500;
    Department(const string& name);
	Department(const Department& other) = delete;
    ~Department();

    Department& operator=(const Department& other) = delete;

	void operator+=(const Employee& newEmployee);
	void operator+=(const Patient& newPatient);
	void operator+=(const Visit& newVisit);
	void operator-=(const Employee& existingEmployee);
	void operator-=(const Patient& existingPatient);
	void operator-=(const Visit& existingVisit);


    const string& getName()									const;
    int getCurrentNumOfPatients()							const;
    int getCurrentNumOfEmployees()							const;
	int getCurrentNumOfVisits()								const;
	const vector<const Employee*> getAllEmployees()			const;
	const vector<const Patient*> getAllPatients()			const;
	const vector<const Visit*> getAllVisits()				const;
    const Patient* getPatientById(int id)					const;
    const Employee* getEmployeeByEmployeeId(int employeeId) const; // employee id
	const Employee* getEmployeeById(int id)					const; // person id
	const Visit* getVisitById(int id)						const;

    void setName(const string& name);

    void addPatient(const Patient* newPatient);
    void removePatientById(int Id);
    void addEmployee(const Employee* newEmployee);
    void removeEmployeeById(int employeeId);
	void addVisit(const Visit* visit);
	void removeVisitById(int visitId);
	
	virtual void onEmployeeRemoved(int employeeId) override;
	virtual void onEmployeeReplaced(const Employee* newPointer) override;
	
	bool operator==(const Department& other);

	friend std::ostream& operator<<(std::ostream& os, const Department& department);
};

#endif /* _DEPARTMENT_H */
