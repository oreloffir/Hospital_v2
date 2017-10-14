#pragma once
#pragma warning( disable : 4290 )  
#ifndef hospital_manager_h
#define hospital_manager_h
#include "DoctorBuilder.h"
#include "NurseBuilder.h"
#include "ResearcherBuilder.h"
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
	vector<Department*> departments;
	vector<Patient*> patients;
	vector<Visit*> visits; // Surgery , Inspection
	vector<Employee*> employees;  // Doctor, Nurse, Researcher, Surgeon, ResearchingDoctor
	vector<EmployeeListener*> employeeListeners;

	int currentNumOfSurgeries;		// Validation usage
	int currentNumOfDoctors;		// Validation usage
	int currentNumOfNurses;			// Validation usage
	int currentNumOfResearchers;	// Validation usage
	int currentNumOfSurgeons;		// Validation usage

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

	/* Department managment */
	const Department& createDepartment(const string& departmentName);
	const Department* getConstDepartmentByName(const string& departmentName) const;
	const vector<const Department*> getAllDepartments() const;
	int getCurrectNumOfDepartments() const;
	void addPatientToDepartment(const Patient* patient, const Department* department);
	void removePatientFromDepartment(const Patient* patient, const Department* department);
	void addEmployeeToDepartment(const Employee* employee, const Department* department);
	void removeEmployeeFromDepartment(const Employee* employee, const Department* department);

	/* Patient Managment */
	const Patient& createPatient(int id, const string& name, const string& dateOfBirth, Person::eGender gender);
	const Patient* getConstPatientById(int patientId) const;
	const vector<const Patient*> getAllPatients() const;
	int getCurrectNumOfPatients() const;
	bool addAllergieToPatient(int patientId, const string& allergieName);

	/* Visit Managment */
	const Inspection& createInspection(const Visit::VisitInfo& visitInfo, string& typeOfInspection);
	const Surgery& createSurgery(const Visit::VisitInfo& visitInfo, SurgeryType* type, int numOfSurgeons = 1);
	const Visit* getConstVisitById(int id) const;
	const vector<const Visit*> getAllVisits() const;
	int getCurrectNumOfVisits() const;
	void addCareGivingEmployeeToVisit(const CareGivingEmployee* cge, int visitId);
	void removeCareGivingEmployeeToVisit(const CareGivingEmployee* cge, int visitId);
	int getCurrentNumOfSurgeries() const;

	/*Employee Managment*/
	const vector<const Employee*> getAllEmployees() const;
	int getCurrectNumOfEmployees() const;
	const Employee* getConstEmployeeById(int employeeId) const;
	/*Doctor*/
	const Doctor& createDoctor(const Employee::employeeInfo employeeInfo, const string& fieldOfExpertise, int numOfDiplomas = 0);
	const Doctor* getConstDoctorById(int id) const;
	void addDiplomaToDoctor(int id);
	int getCurrentNumOfDoctors() const;
	/*Nurse*/
	const Nurse& createNurse(const Employee::employeeInfo employeeInfo, int maxNumOfDuties);
	const Nurse* getConstNurseById(int id) const;
	void addDuty(int id, const string& duty);
	void removeDuty(int id, const string& duty);
	void setMaxNumOfDuties(int id, int max);
	int getCurrentNumOfNurses() const;
	/*Researcher*/
	const Researcher& createResearcher(const Employee::employeeInfo employeeInfo, const string& areaOfResearch);
	const Researcher* getConstResearcherById(int id) const;
	bool addPublicationToResearcher(int researcherId, const string& publicationName);
	int getCurrentNumOfResearchers() const;
	/*Surgeon*/
	const Surgeon& createSurgeon(const Doctor* doctor, bool hasSecurityClearance, int numOfSuccesfulSurgeries = 0, int numOfSurgeries = 0);
	const Surgeon* getConstSurgeonById(int id) const;
	bool performSurgery(const Surgeon* surgeon, const Surgery* surgery) const;
	int getCurrentNumOfSurgeons() const;
	/*Researching doctor*/
	const ResearchingDoctor& createResearchingDoctor(const Doctor* doctor, const string& areaOfResearch, int maxNumOfTestSubjects = 0);
	const ResearchingDoctor* getConstResearchingDoctorById(int id) const;
	void addTestSubjectToRD(int researcherId, const Patient* testSubject) const;
	void removeTestSubjectToRD(int researcherId, const Patient* testSubject) const;

	void addEmployeeListener(EmployeeListener* employeeListener);
	void removeEmployeeListener(EmployeeListener* employeeListener);

	static constexpr int MAX_NUMBER_OF_DEPARTMENTS			= 50;
	static constexpr int MAX_NUMBER_OF_PATIENTS				= 1000;
	static constexpr int MAX_NUMBER_OF_VISITS				= 4000;
	static constexpr int MAX_NUMBER_OF_EMPLOYEES			= 500;
	static constexpr int MAX_NUMBER_OF_EMPLOYEE_LISTENERS	= 1000;
	static const char* ARRAY_MAX_SIZE;

};
#endif
