#pragma once
#ifndef hospital_controller_h
#define hospital_controller_h
#include "hospitalManager.h"
#include <iostream>
using namespace std;

class HospitalController
{
public:
	HospitalController();
	~HospitalController();
	HospitalController(const HospitalController& other)				= delete;
	HospitalController& operator=(const HospitalController& other)	= delete;

	// start
	void run()		const;
	int mainMenu()	const;

	// main selection sub controllers
	void createEntities()								const;
	void selectEntities()								const;
	void printEntities()								const;
	const Employee* createEmployeeSelection()			const;
	void createVisitSelection(const Patient& patient)	const; 
	const Employee* getEmployeeByType()					const;

	// main selection menues
	int createEntitiesMenu()	const;
	int selectEntitiesMenu()	const;
	int printEntitiesMenu()		const;
	int departmentMenu()		const;
	int patientMenu()			const;
	int selectEmployeeTypeMenu()const;
	int createEmployeeMenu()	const;
	int visitMenu()				const;
	int doctorMenu()			const;
	int nurseMenu()				const;
	int researcherMenu()		const;
	int surgeonMenu()			const;
	int researchingDoctorMenu() const;

	/* Creators */
	const Department* createDepartment(bool showSelectMenu = true)									const;
	const Patient* createPatient(bool showSelectMenu = true)										const;
	Employee::employeeInfo createEmployeeInfo()														const;
	const Doctor* createDoctor(bool showSelectMenu = true)											const;
	const Nurse* createNurse(bool showSelectMenu = true)											const;
	const Researcher* createResearcher(bool showSelectMenu = true)									const;
	const Surgeon* createSurgeon(int doctorId = 0, bool showSelectMenu = true)						const;
	const ResearchingDoctor* createResearchingDoctor(int doctorId = 0, bool showSelectMenu = true)	const;
	Visit::VisitInfo& HospitalController::createVisitInfo(const Patient& patient)					const;
	const Surgery* createSurgery(const Patient& patient, bool showSelectMenu = true)				const;
	const Inspection* createInspection(const Patient& patient, bool showSelectMenu = true)			const;

	void deleteEmployeeInfo(Employee::employeeInfo* employeeInfo) 									const;
	void HospitalController::deleteVisitInfo(Visit::VisitInfo visitInfo)							const;

	/* Selectors */
	void selectDepartment(const char* departmentName = nullptr)	const;
	void selectPatient(int patientId = 0)						const;
	void selectEmployee(int employeeId = 0)						const;
	void selectDoctor(int doctorId = 0)							const;
	void selectNurse(int nurseId = 0)							const;
	void selectResearcher(int researcherId = 0)					const;
	void selectSurgeon(int surgeonId = 0)						const;
	void selectResearchingDoctor(int reasearchingDoctorId = 0)	const;
	void selectVisit(int visitId = 0)							const;

	/* Print all */
	void printAllDepartments()									const;
	void printAllPatients()										const;
	void printAllEmployees(const char* employeeType = nullptr)	const;
	void printAllVisits()										const;

	/* Get Object by user id*/
	const Employee* getEmployeeFromUser(int employeeId, const char* employeeClass)									const;
	const Visit* getVisitFromUser(int visitId = 0)																	const;
	const Patient* getPatientFromUser(int patientId = 0)															const;
	const Doctor* getDoctorFromUser(int doctorId = 0)																const;
	const Nurse* getNurseFromUser(int nurseId = 0)																	const;
	const Researcher* getResearcherFromUser(int researcherId = 0)													const;
	const Surgeon* getSurgeonFromUser(int surgeonId = 0)															const;
	const ResearchingDoctor* getResearchingDoctorFromUser(int researchingDoctorId = 0)								const;
	const CareGivingEmployee* getCareGivingEmployeeFromUser(int careGivingEmployeeId = 0)							const;
	const Department* getDepartmentFromUser(const char* departmentName = nullptr)									const;
	const Surgery* getSurgeryFromUser(int surgeryId = 0)															const;

	/* general functions */
	char* getStringFromUser(char* outputBuffer = nullptr) const;
	int getIntegerFromUser(int minVal = INT_MIN, int maxVal = INT_MAX) const;
	double getDoubleFromUser(double minVal = DBL_MIN, double maxVal = DBL_MAX) const;
	bool validateString(const char* str) const;

	static constexpr int CREATE_OPTION	= 1;
	static constexpr int SELECT_OPTION	= 2;
	static constexpr int PRINT_OPTION	= 3;

	static constexpr int CREATE_DEPARTMENT	= 1;
	static constexpr int CREATE_PATIENT		= 2;
	static constexpr int CREATE_EMPLOYEE	= 3;
	static constexpr int CREATE_VISIT		= 4;

	static constexpr int SELECT_DEPARTMENT	= 1;
	static constexpr int SELECT_PATIENT		= 2;
	static constexpr int SELECT_EMPLOYEE	= 3;
	static constexpr int SELECT_VISIT		= 4;

	static constexpr int DEPARTMENT_ADD_PATIENT			= 1;
	static constexpr int DEPARTMENT_REMOVE_PATIENT		= 2;
	static constexpr int DEPARTMENT_ADD_EMPLOYEE		= 3;
	static constexpr int DEPARTMENT_REMOVE_EMPLOYEE		= 4;
	static constexpr int DEPARTMENT_PRINT_ALL_PATIENTS	= 5;
	static constexpr int DEPARTMENT_PRINT_ALL_EMPLOYEES = 6;
	static constexpr int DEPARTMENT_PRINT_ALL_VISITS	= 7;

	static constexpr int VISIT_SURGERY					= 1;
	static constexpr int VISIT_INSPECTION				= 2;
	static constexpr int PRINT_PATIENT_INFO				= 1;
	static constexpr int PRINT_SEEING_STAFF				= 2;
	static constexpr int ADD_CARE_GIVING_EMPLOYEE		= 3;
	static constexpr int REMOVE_CARE_GIVING_EMPLOYEE	= 4;
  
	static constexpr int PATIENT_ADD_ALERGIE	= 1;
	static constexpr int PATIENT_CREATE_VISIT	= 2;
	static constexpr int PATIENT_PRINT_VISITS	= 3;

	static constexpr int EMPLOYEE_CREATE_DOCTOR				= 1;
	static constexpr int EMPLOYEE_CREATE_NURSE				= 2;
	static constexpr int EMPLOYEE_CREATE_SURGEON			= 3;
	static constexpr int EMPLOYEE_CREATE_REASERCHING_DOCTOR = 4;
	static constexpr int EMPLOYEE_CREATE_REASERCHER			= 5;

	static constexpr int EMPLOYEE_TYPE_DOCTOR				= 1;
	static constexpr int EMPLOYEE_TYPE_NURSE				= 2;
	static constexpr int EMPLOYEE_TYPE_SURGEON				= 3;
	static constexpr int EMPLOYEE_TYPE_REASERCHING_DOCTOR	= 4;
	static constexpr int EMPLOYEE_TYPE_REASERCHER			= 5;

	static constexpr int DOCTOR_ADD_DIPLOMA				= 1;
	static constexpr int DOCTOR_TO_SURGEON				= 2;
	static constexpr int DOCTOR_TO_RESEARCHING_DOCTOR	= 3;

	static constexpr int NURSE_GET_DUTIES	= 1;
	static constexpr int NURSE_ADD_DUTY		= 2;
	static constexpr int NURSE_REMOVE_DUTY	= 3;
	
	static constexpr int RESEARCHER_PRINT_AREA_OF_RESEARCH	= 1;
	static constexpr int RESEARCHER_GET_PUBLICATION_NAMES	= 2;
	static constexpr int RESEARCHER_ADD_PUBLICATION			= 3;

	static constexpr int PRINT_DEPARTMENTS	= 1;
	static constexpr int PRINT_PATIENTS		= 2;
	static constexpr int PRINT_EMPLOYEES	= 3;
	static constexpr int PRINT_VISITS		= 4;

	static constexpr int SURGEON_CHECK_SECURITY_CLEARANCE			= 1;
	static constexpr int SURGEON_GET_NUM_OF_SUCCESFULL_SURGERIES	= 2;
	static constexpr int SURGEON_CHECK_SURGERY_CHANCE				= 3;
	static constexpr int SURGEON_PERFORM_SURGERY					= 4;
	static constexpr int SURGEON_ADD_DIPLOMA						= 5;

	static constexpr int RESEARCHING_DOCTOR_ADD_SUBJECT					= 1;
	static constexpr int RESEARCHING_DOCTOR_REMOVE_SUBJECT				= 2;
	static constexpr int RESEARCHING_DOCTOR_GET_CURRENT_NUM_OF_SUBJECTS = 3;
	static constexpr int RESEARCHING_DOCTOR_GET_ALL_OF_SUBJECTS			= 4;
	static constexpr int RESEARCHING_DOCTOR_ADD_DIPLOMA					= 5;

	static constexpr int HELP				= -999;

	static constexpr int MAX_STRING_SIZE	= 30;

	static const char* PRESS_TO_GO_BACK;
	static const char* INVALID_INPUT;
private:
	HospitalManager* hospitalManager;
	char* inputBuffer;
};

#endif