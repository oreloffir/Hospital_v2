#ifndef _VISIT_H
#define _VISIT_H
#include "department.h"
#include "patient.h"
#include "careGivingEmployee.h"
#include "EmployeeListener.h"
#include <string>
#include <iostream>
using namespace std;

class Department;

class Visit : public EmployeeListener
{
public:
	static int visitIdGenerator; // starting from 1
    enum eCare {FIRST_AID, TESTS, SURGERY_PREP, SURGERY};
	static constexpr int MAX_NUM_OF_SEEING_STAFF = 20;
	static const string cares[];

    virtual ~Visit();

    //getters
    const string& getDate()									const;
    const string& getCause()								const;
    const Department* getDepratment()						const;
    const Patient* getPatient()								const;
	const vector<const CareGivingEmployee*> getSeeingStaff()const;
	void printSeeingStaff()									const;
	eCare getTypeOfCare()									const;
	const string& getTypeOfCareName()						const;
    int getMaxNumOfSeeingStaff()							const;
    int getCurrentNumOfSeeingStaff()						const;
	int getVisitId()										const;
	const CareGivingEmployee* getCareGivingEmployeeById(int careGivingEmployeeId) const;
    
    //setters
    void setCause(const string& cause);
    void setTypeOfCare(eCare typeOfCare);
    void addSeeingStaff(const CareGivingEmployee& employee);
    void removeSeeingStaff(int employeeId);
    void rescheduleVisit(const string& newDate);
    void changeDepartment(const Department &other);

	void operator+=(const CareGivingEmployee& cgEmployee);
	void operator-=(const CareGivingEmployee& cgEmployee);

	virtual void toOs(std::ostream& os) const = 0;

	virtual void onEmployeeRemoved(int employeeId) override;
	virtual void onEmployeeReplaced(const Employee* newPointer) override;

	friend std::ostream& operator<<(std::ostream& os, const Visit& visit);

	struct VisitInfo {
		string date;
		string cause;
		const Department* department;
		const Patient* patient;
		Visit::eCare typeOfCare;
	};

protected:
	int visitId;
    string date;
    string cause;
    const Department* department;
    const Patient* patient;
	vector<const CareGivingEmployee*> seeingStaff;
    eCare typeOfCare;

    //ctors
    Visit(const string& date, const string& cause, const Department* department, const Patient* patient, eCare typeOfCare);
	Visit(const Visit& other);
	const Visit& operator=(const Visit& other);
};
#endif /* _VISIT_H */
