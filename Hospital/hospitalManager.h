#pragma once
#ifndef hospital_manager_h
#define hospital_manager_h
#include "doctor.h"
#include "nurse.h"
#include "researchingDoctor.h"
#include "surgeon.h"
#include "department.h"
#include "person.h"
#include "visit.h"
#include "inspection.h"

class HospitalManager
{
private:
	static HospitalManager* instance;
	Department** departments;
	Patient** patients;
	Visit** visits; // Surgery , Inspection
	Employee** employees;  // Doctor, Nurse, Researcher, Surgeon, ResearchingDoctor
	EmployeeListener** employeeListeners;

	int currectNumOfDepartments;
	int currentNumOfPatients;
	int currentNumOfVisits;
	int currentNumOfSurgeries;		// Validation usage
	/* Employees */
	int currentNumOfEmployees; 
	int currentNumOfDoctors;		// Validation usage
	int currentNumOfNurses;			// Validation usage
	int currentNumOfResearchers;	// Validation usage
	int currentNumOfSurgeons;		// Validation usage

	int currentNumOfEmployeeListeners;

	HospitalManager();

	Patient* getPatientById(int patientId)							const;
	Department* getDepartmentByName(const string& departmentName)	const;
	Visit* getVisitById(int visitId)								const;
	Employee* getEmployeeById(int employeeId)						const;
	Doctor* getDoctorById(int doctorId)								const;
	Nurse* getNurseById(int nurseId)								const;
	Researcher* getResercherById(int resercherId)					const;
	ResearchingDoctor* getResearchingDoctorById(int resercherId)	const;
	Surgeon* getSurgeonById(int surgeonId)							const;
public:
	~HospitalManager();
	HospitalManager(HospitalManager& other) = delete;
	HospitalManager& operator=(const HospitalManager& other) = delete;

	static HospitalManager* getInstance();

	static constexpr int MAX_NUMBER_OF_DEPARTMENTS = 50;
	static constexpr int MAX_NUMBER_OF_PATIENTS = 1000;
	static constexpr int MAX_NUMBER_OF_VISITS = 4000;
	static constexpr int MAX_NUMBER_OF_EMPLOYEES = 500;
	static constexpr int MAX_NUMBER_OF_EMPLOYEE_LISTENERS = 1000;

	static const char* ARRAY_MAX_SIZE;
	
	/* Department managment */
	const Department& createDepartment(const string& departmentName) throw(const char*);
	const Department* getConstDepartmentByName(const string& departmentName) const;
	const Department* const* getAllDepartments() const;
	int getCurrectNumOfDepartments() const;
	void addPatientToDepartment(const Patient* patient, const Department* department);
	void removePatientFromDepartment(const Patient* patient, const Department* department);
	void addEmployeeToDepartment(const Employee* employee, const Department* department);
	void removeEmployeeFromDepartment(const Employee* employee, const Department* department);

	/* Patient Managment */
	const Patient& createPatient(int id, const string& name, const string& dateOfBirth, Person::eGender gender) throw(const char*);
	const Patient* getConstPatientById(int patientId) const;
	const Patient* const* getAllPatients() const;
	int getCurrectNumOfPatients() const;
	bool addAllergieToPatient(int patientId, const string& allergieName);

	/* Visit Managment */
	const Inspection& createInspection(const Visit::VisitInfo& visitInfo, string& typeOfInspection) throw(const char*);
	const Surgery& createSurgery(const Visit::VisitInfo& visitInfo, SurgeryType* type, int numOfSurgeons = 1) throw(const char*);
	const Visit* getConstVisitById(int id) const;
	const Visit* const* getAllVisits() const;
	int getCurrectNumOfVisits() const;
	void addCareGivingEmployeeToVisit(const CareGivingEmployee* cge, int visitId);
	void removeCareGivingEmployeeToVisit(const CareGivingEmployee* cge, int visitId);
	int getCurrentNumOfSurgeries() const;

	/*Employee Managment*/
	const Employee* const* getAllEmployees() const;
	int getCurrectNumOfEmployees() const;
	const Employee* getConstEmployeeById(int employeeId) const;
	/*Doctor*/
	const Doctor& createDoctor(const Employee::employeeInfo employeeInfo, const string& fieldOfExpertise, int numOfDiplomas = 0) throw(const char*);
	const Doctor* getConstDoctorById(int id) const;
	void addDiplomaToDoctor(int id);
	int getCurrentNumOfDoctors() const;
	/*Nurse*/
	const Nurse& createNurse(const Employee::employeeInfo employeeInfo, int maxNumOfDuties) throw(const char*);
	const Nurse* getConstNurseById(int id) const;
	void addDuty(int id, const string& duty);
	void removeDuty(int id, const string& duty);
	int getCurrentNumOfNurses() const;
	/*Researcher*/
	const Researcher& createResearcher(const Employee::employeeInfo employeeInfo, const string& areaOfResearch) throw(const char*);
	const Researcher* getConstResearcherById(int id) const;
	bool addPublicationToResearcher(int researcherId, const string& publicationName);
	int getCurrentNumOfResearchers() const;
	/*Surgeon*/
	const Surgeon& createSurgeon(const Doctor* doctor, bool hasSecurityClearance, int numOfSuccesfulSurgeries = 0, int numOfSurgeries = 0) throw(const char*);
	const Surgeon* getConstSurgeonById(int id) const;
	bool performSurgery(const Surgeon* surgeon, const Surgery* surgery) const;
	int getCurrentNumOfSurgeons() const;
	/*Researching doctor*/
	const ResearchingDoctor& createResearchingDoctor(const Doctor* doctor,const string& areaOfResearch, int maxNumOfTestSubjects = 0) throw(const char*);
	const ResearchingDoctor* getConstResearchingDoctorById(int id) const;
	void addTestSubjectToRD(int researcherId, const Patient* testSubject) const;
	void removeTestSubjectToRD(int researcherId, const Patient* testSubject) const;

	void addEmployeeListener(EmployeeListener* employeeListener);
	void removeEmployeeListener(EmployeeListener* employeeListener);
};
#endif