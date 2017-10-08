#ifndef _VISIT_H
#define _VISIT_H

#include "department.h"
#include "patient.h"
#include "careGivingEmployee.h"

class Visit
{
public:
	static int visitIdGenerator; // starting from 1
    enum eCare {FIRST_AID, TESTS, SURGERY_PREP, SURGERY};
	static constexpr int MAX_NUM_OF_SEEING_STAFF = 20;
	static const char* cares[];

    virtual ~Visit();

    void operator+=(const CareGivingEmployee& cgEmployee);
    void operator-=(const CareGivingEmployee& cgEmployee);

    //getters
    const char* getDate()							const;
    const char* getCause()							const;
    const Department* getDepratment()				const;
    const Patient* getPatient()						const;
    const CareGivingEmployee** getSeeingStaff()		const;
	eCare getTypeOfCare()							const;
	const char* getTypeOfCareName()					const;
    int getMaxNumOfSeeingStaff()					const;
    int getCurrentNumOfSeeingStaff()				const;
	int getVisitId()								const;
	const CareGivingEmployee* getCareGivingEmployeeById(int careGivingEmployeeId) const;
    
    //setters
    void setCause(const char* cause);
    void setTypeOfCare(eCare typeOfCare);
    
    //methods
    void addSeeingStaff(const CareGivingEmployee& employee);
    void removeSeeingStaff(int employeeId);
    void rescheduleVisit(const char* newDate);
    void changeDepartment(const Department &other);

	virtual void toOs(std::ostream& os) const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Visit& visit);

	struct VisitInfo {
		char* date;
		char* cause;
		const Department* department;
		const Patient* patient;
		Visit::eCare typeOfCare;
	};

protected:
    char* date;
    char* cause;
    const Department* department;
    const Patient* patient;
	int visitId;
    int currentNumOfSeeingStaff;
    CareGivingEmployee const* * seeingStaff;
    eCare typeOfCare;

    //ctors
    Visit(const char* date, const char* cause, const Department* department, const Patient* patient, eCare typeOfCare);
	Visit(const Visit& other);
	const Visit& operator=(const Visit& other);
	void free();
};


#endif /* _VISIT_H */
