#include "HospitalController.h"

HospitalController::HospitalController()
{
	this->inputBuffer		= new char[MAX_STRING_SIZE];
}
HospitalController::~HospitalController()
{
	delete[] inputBuffer;
}

void HospitalController::run() const
{
	cout << "Welcome to Hospital Managment system" << endl;
	int selectedOption;

	while (true) {
		selectedOption = mainMenu();
		switch (selectedOption)
		{
		case CREATE_OPTION:
			createEntities();
			break;
		case SELECT_OPTION:
			selectEntities();
			break;
		case PRINT_OPTION:
			printEntities();
			break;
		default:
			return;
			break;
		}
	}
}
int HospitalController::mainMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << CREATE_OPTION << ". Create - creating departments, employees, patients, visits, etc..." << endl;
	cout << "\t" << SELECT_OPTION << ". Select - select an existing department, employees, patients, visits, etc..." << endl;
	cout << "\t" << PRINT_OPTION << ". Print - print all departments informations, patients, visits, etc..." << endl;
	cout << "Press any other number to exit" << endl;
	return getIntegerFromUser();
}

/* sub controllers */
void HospitalController::createEntities() const
{
	int selectedOption;
	while (true) {
		selectedOption = createEntitiesMenu();
		switch (selectedOption)
		{
		case CREATE_DEPARTMENT:
			createDepartment();
			break;
		case CREATE_PATIENT:
			createPatient();
			break;
		case CREATE_EMPLOYEE:
			createEmployeeSelection();
			break;
		default:
			return;
			break;
		}
	}

}
void HospitalController::selectEntities() const
{
	int selectedOption;
	while (true) {
		selectedOption = selectEntitiesMenu();
		switch (selectedOption)
		{
		case SELECT_DEPARTMENT:
			selectDepartment();
			break;
		case SELECT_PATIENT:
			selectPatient();
			break;
		case SELECT_EMPLOYEE:
			selectEmployee();
			break;
		case SELECT_VISIT:
			selectVisit();
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::printEntities() const
{
	while(true)
	{
		switch (printEntitiesMenu())
		{
		case PRINT_DEPARTMENTS:
			printAllDepartments();
			break;
		case PRINT_PATIENTS:
			printAllPatients();
			break;
		case PRINT_EMPLOYEES:
			printAllEmployees();
			break;
		case PRINT_VISITS:
			printAllVisits();
			break;
		default:
			return;
		}
	}
}
void HospitalController::createVisitSelection(const Patient& patient) const
{
	// Dependances
	if (HospitalManager::getInstance()->getCurrectNumOfDepartments() == 0) {
		cout << "To create a visit, please create a department first." << endl;
		return;
	}
	if (HospitalManager::getInstance()->getCurrectNumOfPatients() == 0) {
		cout << "To create a visit, please create a patient first." << endl;
		return;
	}

	cout << "--------------- Create a new visit --------------" << endl;
	cout << "Welcome to creating new visit wizard." << endl;
	cout << "Please select visit type " << VISIT_SURGERY << " - sergery " << VISIT_INSPECTION << " - inspection: ";
	int selectedVisitType = getIntegerFromUser(VISIT_SURGERY, VISIT_INSPECTION);

	switch (selectedVisitType)
	{
	case VISIT_SURGERY:
		createSurgery(patient);
		break;
	case VISIT_INSPECTION:
		createInspection(patient);
		break;
	default:
		return;
		break;
	}
}
const Employee* HospitalController::createEmployeeSelection() const
{
	int selectedOption;
	while (true) {
		selectedOption = createEmployeeMenu();
		switch (selectedOption)
		{
		case EMPLOYEE_CREATE_DOCTOR:
			return createDoctor();
		case EMPLOYEE_CREATE_NURSE:
			return createNurse();
		case EMPLOYEE_CREATE_REASERCHER:
			return createResearcher();
		case EMPLOYEE_CREATE_SURGEON:
			return createSurgeon();
		case EMPLOYEE_CREATE_REASERCHING_DOCTOR:
			return createResearchingDoctor();
		default:
			return nullptr;
			break;
		}
	}
}
const Employee* HospitalController::getEmployeeByType() const
{
	while (true)
	{
		switch (selectEmployeeTypeMenu())
		{
		case EMPLOYEE_TYPE_DOCTOR:
			return getDoctorFromUser();
			break;
		case EMPLOYEE_TYPE_NURSE:
			return getNurseFromUser();
			break;
		case EMPLOYEE_TYPE_REASERCHER:
			return getResearcherFromUser();
			break;
		case EMPLOYEE_TYPE_SURGEON:
			return getSurgeonFromUser();
			break;
		case EMPLOYEE_TYPE_REASERCHING_DOCTOR:
			return getResearchingDoctorFromUser();
			break;
		default:
			return nullptr;
			break;
		}
	}


}

/* Menues*/
int HospitalController::createEntitiesMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << CREATE_DEPARTMENT << ". Create new department." << endl;
	cout << "\t" << CREATE_PATIENT << ". Create new patient." << endl;
	cout << "\t" << CREATE_EMPLOYEE << ". Create new employee." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::selectEntitiesMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << SELECT_DEPARTMENT << ". Select department." << endl;
	cout << "\t" << SELECT_PATIENT << ". Select patient." << endl;
	cout << "\t" << SELECT_EMPLOYEE << ". Select employee." << endl;
	cout << "\t" << SELECT_VISIT << ". Select visit." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::printEntitiesMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << PRINT_DEPARTMENTS << ". Print all departments." << endl;
	cout << "\t" << PRINT_PATIENTS << ". Print all patients." << endl;
	cout << "\t" << PRINT_EMPLOYEES << ". Print all employees." << endl;
	cout << "\t" << PRINT_VISITS << ". Print all visits." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::patientMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << PATIENT_ADD_ALERGIE << ". Add alergie." << endl;
	cout << "\t" << PATIENT_CREATE_VISIT << ". Create new visit." << endl;
	cout << "\t" << PATIENT_PRINT_VISITS << ". Print all visits." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::departmentMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << DEPARTMENT_ADD_PATIENT << ". Add patient." << endl;
	cout << "\t" << DEPARTMENT_REMOVE_PATIENT << ". Remove patient." << endl;
	cout << "\t" << DEPARTMENT_ADD_EMPLOYEE << ". Add employee" << endl;
	cout << "\t" << DEPARTMENT_REMOVE_EMPLOYEE << ". Remove employee." << endl;
	cout << "\t" << DEPARTMENT_PRINT_ALL_PATIENTS << ". Print all department patients." << endl;
	cout << "\t" << DEPARTMENT_PRINT_ALL_EMPLOYEES << ". Print all department employees." << endl;
	cout << "\t" << DEPARTMENT_PRINT_ALL_VISITS << ". Print all department visits." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::selectEmployeeTypeMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << EMPLOYEE_TYPE_DOCTOR << ". Select doctor." << endl;
	cout << "\t" << EMPLOYEE_TYPE_NURSE << ". Select nurse." << endl;
	cout << "\t" << EMPLOYEE_TYPE_SURGEON << ". Select surgeon." << endl;
	cout << "\t" << EMPLOYEE_TYPE_REASERCHING_DOCTOR << ". Select researching doctor." << endl;
	cout << "\t" << EMPLOYEE_TYPE_REASERCHER << ". Select researcher." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::createEmployeeMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << EMPLOYEE_CREATE_DOCTOR << ". Create new doctor." << endl;
	cout << "\t" << EMPLOYEE_CREATE_NURSE << ". Create new nurse." << endl;
	cout << "\t" << EMPLOYEE_CREATE_SURGEON << ". Create new surgeon." << endl;
	cout << "\t" << EMPLOYEE_CREATE_REASERCHING_DOCTOR << ". Create new researching doctor." << endl;
	cout << "\t" << EMPLOYEE_CREATE_REASERCHER << ". Create new researcher." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::visitMenu()	const
{
	cout << "Actions:" << endl;
	cout << "\t" << PRINT_PATIENT_INFO << ". Print patient information." << endl;
	cout << "\t" << PRINT_SEEING_STAFF << ". Print seeing staff." << endl;
	cout << "\t" << ADD_CARE_GIVING_EMPLOYEE << ". Add care giving employee." << endl;
	cout << "\t" << REMOVE_CARE_GIVING_EMPLOYEE << ". Remove care giving employee." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::doctorMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << DOCTOR_ADD_DIPLOMA << ". Add diploma." << endl;
	cout << "\t" << DOCTOR_TO_SURGEON << ". Make doctor surgeon." << endl;
	cout << "\t" << DOCTOR_TO_RESEARCHING_DOCTOR << ". Make doctor researcher doctor." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::nurseMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << NURSE_GET_DUTIES << ". Get duties." << endl;
	cout << "\t" << NURSE_ADD_DUTY << ". Add duty." << endl;
	cout << "\t" << NURSE_REMOVE_DUTY << ". Remove duty." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::researcherMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << RESEARCHER_PRINT_AREA_OF_RESEARCH << ". Get area of search." << endl;
	cout << "\t" << RESEARCHER_GET_PUBLICATION_NAMES << ". Get publiction names." << endl;
	cout << "\t" << RESEARCHER_ADD_PUBLICATION << ". Add publiction." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::surgeonMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << SURGEON_CHECK_SECURITY_CLEARANCE << ". Check surgeon security clearance." << endl;
	cout << "\t" << SURGEON_GET_NUM_OF_SUCCESFULL_SURGERIES << ". Get num of succesfull surgeries." << endl;
	cout << "\t" << SURGEON_CHECK_SURGERY_CHANCE << ". Get surgery chances." << endl;
	cout << "\t" << SURGEON_PERFORM_SURGERY << ". Perform surgery." << endl;
	cout << "\t" << SURGEON_ADD_DIPLOMA << ". Add diploma." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}
int HospitalController::researchingDoctorMenu() const
{
	cout << "Actions:" << endl;
	cout << "\t" << RESEARCHING_DOCTOR_ADD_SUBJECT << ". Add test subject." << endl;
	cout << "\t" << RESEARCHING_DOCTOR_REMOVE_SUBJECT << ". Remove test subject." << endl;
	cout << "\t" << RESEARCHING_DOCTOR_GET_CURRENT_NUM_OF_SUBJECTS << ". Get current num of test subjects." << endl;
	cout << "\t" << RESEARCHING_DOCTOR_GET_ALL_OF_SUBJECTS << ". Get all of test subjects." << endl;
	cout << "\t" << RESEARCHING_DOCTOR_ADD_DIPLOMA << ". Add diploma." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	return getIntegerFromUser();
}

/* Creators */
const Department* HospitalController::createDepartment(bool showSelectMenu) const
{
	cout << "--------------- Create a new department --------------" << endl;
	cout << "Welcome to creating new department wizard." << endl;
	cout << "Please enter department name: ";

	char* departmentName = getStringFromUser();
	const Department& deprtment = HospitalManager::getInstance()->createDepartment(departmentName);

	cout << "New department was created" << endl;

	delete[] departmentName;

	if (showSelectMenu)
		selectDepartment(deprtment.getName());

	return &deprtment;
}
const Patient* HospitalController::createPatient(bool showSelectMenu) const
{
	cout << "--------------- Create a new patient --------------" << endl;
	cout << "Welcome to creating new patient wizard." << endl;

	cout << "Please enter patient id: ";
	int patientId = getIntegerFromUser(1);
	cout << "Please enter patient name: ";
	char* parientName = getStringFromUser();
	cout << "Please enter patient date of birth: ";
	char* patientDateOfBirth = getStringFromUser();
	cout << "Please enter patient gender 0 - male , 1 - female (default 0): ";
	Person::eGender patientGender = (Person::eGender)getIntegerFromUser(Person::MALE, Person::FEMALE);

	const Patient& patient = HospitalManager::getInstance()->createPatient(patientId, parientName, patientDateOfBirth, patientGender);

	delete[] parientName;
	delete[] patientDateOfBirth;

	cout << "New patient was created" << endl;

	if(showSelectMenu)
		selectPatient(patient.getId());

	return &patient;
}
const Doctor* HospitalController::createDoctor(bool showSelectMenu) const
{
	cout << "--------------- Create a new doctor --------------" << endl;
	cout << "Welcome to creating new doctor wizard." << endl;

	Employee::employeeInfo employeeInfo = createEmployeeInfo();

	cout << "Please enter doctor field of expertise: ";
	char* fieldOfExpertise = getStringFromUser();
	cout << "Please enter doctor num of diplomas: ";
	int numOfDiplomas = getIntegerFromUser(0);

	const Doctor& doctor = HospitalManager::getInstance()->createDoctor(employeeInfo, fieldOfExpertise, numOfDiplomas);

	cout << "New doctor was created" << endl;
	deleteEmployeeInfo(&employeeInfo);
	delete[] fieldOfExpertise;

	if(showSelectMenu)
		selectDoctor(doctor.getEmployeeId());
	
	return &doctor;
}
const Nurse* HospitalController::createNurse(bool showSelectMenu) const
{
	cout << "--------------- Create a new nurse --------------" << endl;
	cout << "Welcome to creating new nurse wizard." << endl;

	Employee::employeeInfo employeeInfo = createEmployeeInfo();

	cout << "Please enter nurse num of max num of duties: ";
	int maxNumOfDuties = getIntegerFromUser(0);

	const Nurse& nurse = HospitalManager::getInstance()->createNurse(employeeInfo, maxNumOfDuties);

	cout << "New nurse was created" << endl;
	deleteEmployeeInfo(&employeeInfo);

	if(showSelectMenu)
		selectNurse(nurse.getEmployeeId());

	return &nurse;
}
const Researcher* HospitalController::createResearcher(bool showSelectMenu) const
{
	cout << "--------------- Create a new researcher --------------" << endl;
	cout << "Welcome to reasercher new researcher wizard." << endl;

	Employee::employeeInfo employeeInfo = createEmployeeInfo();

	cout << "Please enter researcher area of research: ";
	char* areaOfResearch = getStringFromUser();

	const Researcher& researcher = HospitalManager::getInstance()->createResearcher(employeeInfo, areaOfResearch);

	cout << "New researcher was created" << endl;
	deleteEmployeeInfo(&employeeInfo);
	delete[] areaOfResearch;

	if(showSelectMenu)
		selectResearcher(researcher.getEmployeeId());
	
	return &researcher;
}
const Surgeon* HospitalController::createSurgeon(int theDoctorId, bool showSelectMenu) const
{
	int doctorId = theDoctorId;
	if (doctorId == 0)
	{
		cout << "--------------- Create a new surgeon --------------" << endl;
		doctorId = createDoctor(false)->getEmployeeId();
	}
	else
		cout << "--------------- Make the doctor a surgeon --------------" << endl;

	const Doctor* doctor = HospitalManager::getInstance()->getConstDoctorById(doctorId);
	cout << "Please enter surgeon has security clearance 0-False 1-True: ";
	bool securityClearance = getIntegerFromUser(0, 1);
	
	const Surgeon& surgeon = HospitalManager::getInstance()->createSurgeon(doctor, securityClearance);

	if(showSelectMenu)
		selectSurgeon(surgeon.getEmployeeId());
	
	return &surgeon;
}
const ResearchingDoctor* HospitalController::createResearchingDoctor(int theDoctorId, bool showSelectMenu) const
{
	int doctorId = theDoctorId;
	int researcherId = 0;
	if (doctorId == 0)
	{
		cout << "--------------- Create a researching doctor --------------" << endl;
		doctorId = createDoctor(false)->getEmployeeId();
	}
	else
		cout << "--------------- Make the doctor a researching doctor --------------" << endl;
	
	const Doctor* doctor = HospitalManager::getInstance()->getConstDoctorById(doctorId);

	cout << "Please enter researcher area of research: ";
	char* areaOfResearch = getStringFromUser();
	cout << "Please enter the max number of test subjects: ";
	int maxNumOfTestSubjects = getIntegerFromUser(0);
	
	const ResearchingDoctor& researchingDoctor = HospitalManager::getInstance()->createResearchingDoctor(doctor, areaOfResearch, maxNumOfTestSubjects);
	
	delete[] areaOfResearch;

	if(showSelectMenu)
		selectResearchingDoctor(researchingDoctor.getEmployeeId());
	
	return &researchingDoctor;
}
const Surgery* HospitalController::createSurgery(const Patient& patient, bool showSelectMenu) const
{
	Visit::VisitInfo visitInfo = createVisitInfo(patient);
	SurgeryType* type;

	cout << "Please enter surgery type name: ";
	char *name = getStringFromUser();
	cout << "Please enter surgery duration in minutes: ";
	int durationMin = getIntegerFromUser(1);
	cout << "Please enter approximate precentage of success: ";
	float precentageOfSuccess = (float) getDoubleFromUser(1, 100);
	cout << "Please enter number of surgeons: ";
	int numOfSurgeons = getIntegerFromUser(1);
	
	type = new SurgeryType(name, durationMin, precentageOfSuccess, numOfSurgeons);
	const Surgery& surgery = HospitalManager::getInstance()->createSurgery(visitInfo, type, numOfSurgeons);

	delete type;
	delete[] name;
	deleteVisitInfo(visitInfo);

	if (showSelectMenu)
		selectVisit(surgery.getVisitId());

	return &surgery;
}
const Inspection* HospitalController::createInspection(const Patient& patient, bool showSelectMenu) const
{
	Visit::VisitInfo visitInfo = createVisitInfo(patient);
	cout << "Please enter type of Inspection: ";
	char* typeOfInspection = getStringFromUser();

	const Inspection& inspection = HospitalManager::getInstance()->createInspection(visitInfo, typeOfInspection);

	deleteVisitInfo(visitInfo);
	delete[] typeOfInspection;

	if (showSelectMenu)
		selectVisit(inspection.getVisitId());

	return &inspection;
}
Employee::employeeInfo HospitalController::createEmployeeInfo() const
{
	Employee::employeeInfo employee;
	cout << "Please enter person id: ";
	employee.id = getIntegerFromUser(1);
	cout << "Please enter employee name: ";
	employee.name = getStringFromUser();
	cout << "Please enter employee date of birth: ";
	employee.dateOfBirth = getStringFromUser();
	cout << "Please enter employee gender 0 - male , 1 - female: ";
	employee.gender = (Person::eGender)getIntegerFromUser(Person::MALE, Person::FEMALE);
	cout << "Please enter employee start working date: ";
	employee.startWorkingDate = getStringFromUser();
	cout << "Please enter employee rank 0-JUNIOR 1-SENIOR: ";
	employee.employeeRank = (Employee::eRank)getIntegerFromUser(Employee::JUNIOR, Employee::SENIOR);
	cout << "Please enter employee salary: ";
	employee.salary = getDoubleFromUser();
	cout << "Please enter employee area of training: ";
	employee.areaOfTraining = getStringFromUser();
	cout << "Please enter employee seniority years: ";
	employee.seniorityYears = (float)getDoubleFromUser();

	return employee;
}
Visit::VisitInfo& HospitalController::createVisitInfo(const Patient& patient) const
{
	const Department* department = nullptr;

	cout << "Please enter visit date: ";
	char* date = getStringFromUser();
	cout << "Please enter visit cause: ";
	char* cause = getStringFromUser();
	department = getDepartmentFromUser();
	cout << "Please enter type of care 0-First Aid  1-Tests  2-Surgery prep  3-Surgery: ";
	Visit::eCare typeOfCare = (Visit::eCare)getIntegerFromUser(Visit::FIRST_AID, Visit::SURGERY);

	Visit::VisitInfo visitInfo;
	visitInfo.date = date;
	visitInfo.cause = cause;
	visitInfo.patient = &patient;
	visitInfo.department = department;
	visitInfo.typeOfCare = typeOfCare;

	return visitInfo;
}
void HospitalController::deleteEmployeeInfo(Employee::employeeInfo* employeeInfo) const
{
	delete[] employeeInfo->name;
	delete[] employeeInfo->dateOfBirth;
	delete[] employeeInfo->startWorkingDate;
	delete[] employeeInfo->areaOfTraining;
}
void HospitalController::deleteVisitInfo(Visit::VisitInfo visitInfo) const
{
	delete[] visitInfo.cause;
	delete[] visitInfo.date;
}

/* Selectors */
void HospitalController::selectDepartment(const char* departmentName) const
{
	if (HospitalManager::getInstance()->getCurrectNumOfDepartments() == 0)
	{
		cout << "No departments found." << endl;
		return;
	}
	const Department* department = getDepartmentFromUser(departmentName);
	if (department == nullptr)
		return;
	cout << *department << endl;

	const Patient* patient;
	const Employee* employee;
	const Patient* const* patients;
	const Employee* const* employees;
	const Visit* const* visits;
	int amount;

	while (true)
	{
		switch (departmentMenu())
		{
		case DEPARTMENT_ADD_PATIENT:
			patient = getPatientFromUser();
			if (patient == nullptr)
				continue;
			HospitalManager::getInstance()->addPatientToDepartment(patient, department);
			break;

		case DEPARTMENT_REMOVE_PATIENT:
			patient = getPatientFromUser();
			if (patient == nullptr)
				continue;
			HospitalManager::getInstance()->removePatientFromDepartment(patient, department);
			break;

		case DEPARTMENT_ADD_EMPLOYEE:
			employee = getEmployeeByType();
			if (employee == nullptr)
				continue;
			HospitalManager::getInstance()->addEmployeeToDepartment(employee, department);
			break;

		case DEPARTMENT_REMOVE_EMPLOYEE:
			employee = getEmployeeByType();
			if (employee == nullptr)
				continue;
			HospitalManager::getInstance()->removeEmployeeFromDepartment(employee, department);
			break;

		case DEPARTMENT_PRINT_ALL_PATIENTS:
			patients = department->getAllPatients();
			amount = department->getCurrentNumOfPatients();
			if (amount == 0)
				cout << "No patients found." << endl;
			else
				for (int i = 0; i < amount; i++)
					cout << *patients[i] << endl;
			break;

		case DEPARTMENT_PRINT_ALL_EMPLOYEES:
			employees = department->getAllEmployees();
			amount = department->getCurrentNumOfEmployees();
			if (amount == 0)
				cout << "No employees found." << endl;
			else
				for (int i = 0; i < amount; i++)
					cout << *employees[i] << endl;
			break;

		case DEPARTMENT_PRINT_ALL_VISITS:
			visits = department->getAllVisits();
			amount = department->getCurrentNumOfVisits();
			if (amount == 0)
				cout << "No visits found." << endl;
			else
				for (int i = 0; i < amount; i++)
					cout << *visits[i] << endl;
			break;

		default:
			return;
			break;
		}
	}
}
void HospitalController::selectPatient(int patientId) const
{
	const Patient* patient = getPatientFromUser(patientId);
	if (patient == nullptr)
		return;

	cout << (Person&)*patient << endl;

	char* alergie;

	while (true)
	{
		switch (patientMenu())
		{
		case PATIENT_ADD_ALERGIE:
			cout << "Please insert an alergie name: ";
			alergie = getStringFromUser();
			HospitalManager::getInstance()->addAllergieToPatient(patient->getId(), alergie);
			delete alergie;
			break;
		case PATIENT_CREATE_VISIT:
			createVisitSelection(*patient);
			break;
		case PATIENT_PRINT_VISITS:
			patient->printVisits();
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::selectDoctor(int doctorId) const
{
	const Doctor* doctor = getDoctorFromUser(doctorId);

	cout << (Person&)*doctor << endl;

	while (true)
	{
		switch (doctorMenu())
		{
		case DOCTOR_ADD_DIPLOMA:
			HospitalManager::getInstance()->addDiplomaToDoctor(doctor->getEmployeeId());
			break;
		case DOCTOR_TO_SURGEON:
			createSurgeon(doctor->getEmployeeId());
			return;
		case DOCTOR_TO_RESEARCHING_DOCTOR:
			createResearchingDoctor(doctor->getEmployeeId());
			return;
		default:
			return;
		}
	}
}
void HospitalController::selectNurse(int nurseId) const
{
	const Nurse* nurse = getNurseFromUser(nurseId);
	const LinkedList<string>* duties;
	cout << (Person&)*nurse << endl;

	while (true)
	{
		switch (nurseMenu())
		{
		case NURSE_GET_DUTIES:
			if (nurse != nullptr)
			{
				duties = &nurse->getDuties();
				cout << "================= " << nurse->getName() << " Duties =================" << endl;
				if (duties->getSize() > 0)
					cout << duties << endl;
			}
			else
				cout << "================= Invalid nurse id =================" << endl;
			break;
		case NURSE_ADD_DUTY:
			cout << "Enter a new duty name: ";
			HospitalManager::getInstance()->addDuty(nurse->getEmployeeId(), string(getStringFromUser()));
			break;
		case NURSE_REMOVE_DUTY:
			cout << "Enter a duty name to remove: ";
			HospitalManager::getInstance()->removeDuty(nurse->getEmployeeId(), string(getStringFromUser()));
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::selectResearcher(int researcherId) const
{
	const Researcher* researcher = getResearcherFromUser(researcherId);
	const char* const* names;
	cout << (Person&)*researcher << endl;

	char* publicationName;

	while (true)
	{
		switch (researcherMenu())
		{
		case RESEARCHER_PRINT_AREA_OF_RESEARCH:
			if (researcher != nullptr)
			{
				cout << "================= " << researcher->getName() << " Researcher =================" << endl;
				cout << "Area of reserach: " << researcher->getAreaOfResearch() << endl;
			}
			else
				cout << "================= Invalid researcher id =================" << endl;
			break;
		case RESEARCHER_GET_PUBLICATION_NAMES:
			if (researcher != nullptr)
			{
				names = researcher->getPublicationsNames();
				int numOfPublications = researcher->getNumOfPublications();
				cout << "================= " << researcher->getName() << " publication names =================" << endl;
				if (numOfPublications == 0)
					cout << "\t - Researcher has no publications yet." << endl;
				for (int i = 0; i < numOfPublications; i++)
					cout << "\t - " << names[i] << endl;
			}
			else
				cout << "================= Invalid researcher id =================" << endl;
			break;
		case RESEARCHER_ADD_PUBLICATION:
			cout << "Please insert a publication name: ";
			publicationName = getStringFromUser();
			HospitalManager::getInstance()->addPublicationToResearcher(researcher->getEmployeeId(), publicationName);
			delete publicationName;
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::selectSurgeon(int surgeonId) const
{
	const Surgeon* surgeon = getSurgeonFromUser(surgeonId);
	if (surgeon == nullptr)
	{
		cout << "================= Invalid surgeon id =================" << endl;
		return;
	}
	cout << (Person&)*surgeon << endl;

	const Surgery* surgery;

	while (true)
	{
		switch (surgeonMenu())
		{
		case SURGEON_CHECK_SECURITY_CLEARANCE:
			if (surgeon->hasSecurityClearance())
				cout << "Surgeon has security clearance" << endl;
			else
				cout << "Surgeon does not have security clearance" << endl;
			break;
		case SURGEON_GET_NUM_OF_SUCCESFULL_SURGERIES:
			cout << "Surgeon has " << (surgeon->getNumOfSuccesfullSurgeries()) << " succesfull sugeries" << endl;
			break;
		
		case SURGEON_CHECK_SURGERY_CHANCE:
			surgery = getSurgeryFromUser(0);
			cout << "Surgeon has " << (surgeon->getSurgeryChances(surgery)) << "% to succses this sugery" << endl;
			break;
		
		case SURGEON_PERFORM_SURGERY:
			surgery = getSurgeryFromUser(0);
			if (surgery != nullptr)
			{
				if (surgery->getIsDone())
					cout << "Surgery number " << surgery->getVisitId() << " Already done." << endl;
				else {
					HospitalManager::getInstance()->performSurgery(surgeon, surgery);
					if(surgery->getIsDone() && surgery->getSuccsesfullSurgery())
						cout << "The surgery was successful" << endl;
					else
						cout << "The surgery failed" << endl;
				}
			}
			break;
		case SURGEON_ADD_DIPLOMA:
			HospitalManager::getInstance()->addDiplomaToDoctor(surgeon->getEmployeeId());
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::selectResearchingDoctor(int researchingDoctorId) const
{
	const ResearchingDoctor* researchingDoctor = getResearchingDoctorFromUser(researchingDoctorId);
	const Patient* const* testSubjects;
	cout << (Person&)*researchingDoctor << endl;

	char* publicationName = nullptr;

	while (true)
	{
		switch (researchingDoctorMenu())
		{
		case RESEARCHING_DOCTOR_ADD_SUBJECT:
		{
			if (researchingDoctor != nullptr)
			{
				HospitalManager::getInstance()->addTestSubjectToRD(researchingDoctor->getEmployeeId(), getPatientFromUser());
				cout << "Researching Doctor add a new test subject" << endl;
			}
			else
				cout << "================= Invalid researchingDoctor id =================" << endl;
			break;
		}
			
		case RESEARCHING_DOCTOR_REMOVE_SUBJECT:
		{
			if (researchingDoctor != nullptr)
			{
				HospitalManager::getInstance()->removeTestSubjectToRD(researchingDoctor->getEmployeeId(), getPatientFromUser());
				cout << "Researching Doctor remove test subject" << endl;
			}
			else
				cout << "================= Invalid researchingDoctor id =================" << endl;
			break;
		}
			
		case RESEARCHING_DOCTOR_GET_CURRENT_NUM_OF_SUBJECTS:
		{
			if (researchingDoctor != nullptr)
			{
				cout << "Researching Doctor has "<< researchingDoctor->getCurrentNumOfTestSubjects() <<" test subject" << endl;
				break;
			}
			else
				cout << "================= Invalid researchingDoctor id =================" << endl;
			break;
		}
		case RESEARCHING_DOCTOR_GET_ALL_OF_SUBJECTS:
		{
			if (researchingDoctor != nullptr)
			{
				testSubjects = researchingDoctor->getTestSubjects();
				cout << "================= " << researchingDoctor->getName() << " test subjects =================" << endl;
				for (int i = 0; i < researchingDoctor->getCurrentNumOfTestSubjects(); i++)
					cout << "\t - " << *testSubjects[i] << endl;
			}
			else
				cout << "================= Invalid nurse id =================" << endl;
			break;
		}
		case RESEARCHING_DOCTOR_ADD_DIPLOMA:
			HospitalManager::getInstance()->addDiplomaToDoctor(researchingDoctor->getEmployeeId());
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::selectEmployee(int employeeId) const
{
	while (true)
	{
		switch (selectEmployeeTypeMenu())
		{
		case EMPLOYEE_TYPE_DOCTOR:
			selectDoctor();
			break;
		case EMPLOYEE_TYPE_NURSE:
			selectNurse();
			break;
		case EMPLOYEE_TYPE_REASERCHER:
			selectResearcher();
			break;
		case EMPLOYEE_TYPE_SURGEON:
			selectSurgeon();
			break;
		case EMPLOYEE_TYPE_REASERCHING_DOCTOR:
			selectResearchingDoctor();
			break;
		default:
			return;
			break;
		}
	}
}
void HospitalController::selectVisit(int visitId) const
{
	const Visit* visit = getVisitFromUser(visitId);
	if (visit == nullptr)
		return;
	cout << *visit << endl;

	const CareGivingEmployee** cges = nullptr;
	const CareGivingEmployee* cge = nullptr;

	while (true)
	{
		switch (visitMenu())
		{
		case PRINT_PATIENT_INFO:
			cout << *visit->getPatient() << endl;
			break;
		case PRINT_SEEING_STAFF:
			cges = visit->getSeeingStaff();
			for (int i = 0; i < visit->getCurrentNumOfSeeingStaff(); i++)
				cout << *cges[i] << endl;
			if (visit->getCurrentNumOfSeeingStaff() == 0)
				cout << "No care giving employees set yet." << endl;
			break;
		case ADD_CARE_GIVING_EMPLOYEE:
			cge = getCareGivingEmployeeFromUser();
			if (cge == nullptr)
				return;
			HospitalManager::getInstance()->addCareGivingEmployeeToVisit(cge, visit->getVisitId());
			break;
		case REMOVE_CARE_GIVING_EMPLOYEE:
			cge = getCareGivingEmployeeFromUser();
			if (cge == nullptr)
				return;
			HospitalManager::getInstance()->removeCareGivingEmployeeToVisit(cge, visit->getVisitId());
			break;
		default:
			return;
			break;
		}
	}

	return;
}

/* Print all */
void HospitalController::printAllDepartments() const
{
	const Department* const* allDepartments = HospitalManager::getInstance()->getAllDepartments();
	int numberOfDepartments = HospitalManager::getInstance()->getCurrectNumOfDepartments();

	if (numberOfDepartments == 0)
		cout << "No departments created yet." << endl;
	else
		for (int i = 0; i < numberOfDepartments; i++)
		{
			cout << *allDepartments[i] << endl;
		}
}
void HospitalController::printAllPatients() const
{
	const Patient* const* allPatients = HospitalManager::getInstance()->getAllPatients();
	int numberOfPatients = HospitalManager::getInstance()->getCurrectNumOfPatients();

	if (numberOfPatients == 0)
		cout << "No patients created yet." << endl;
	else
		for (int i = 0; i < numberOfPatients; i++)
		{
			cout << *allPatients[i] << endl;
		}
}
void HospitalController::printAllEmployees(const char* employeeType) const
{
	const Employee* const* allEmployees = HospitalManager::getInstance()->getAllEmployees();
	int numberOfEmployees = HospitalManager::getInstance()->getCurrectNumOfEmployees();

	if (numberOfEmployees == 0)
		cout << "No employees created yet." << endl;
	else
		for (int i = 0; i < numberOfEmployees; i++)
		{
			cout << *allEmployees[i] << endl;
		}
}
void HospitalController::printAllVisits() const
{
	const Visit* const* allVisits = HospitalManager::getInstance()->getAllVisits();
	int numberOfVisits = HospitalManager::getInstance()->getCurrectNumOfVisits();

	if (numberOfVisits == 0)
		cout << "No visits created yet." << endl;
	else
		for (int i = 0; i < numberOfVisits; i++)
		{
			cout << *allVisits[i] << endl;
		}
}

/* Get Object from user*/
const Visit* HospitalController::getVisitFromUser(int visitId) const
{
	if (HospitalManager::getInstance()->getCurrectNumOfVisits() == 0)
	{
		cout << "No visits found" << endl;
		return nullptr;
	}
	bool invalidVisitId = false;
	const Visit* visit = nullptr;
	int inputVisitId = visitId;

	while (invalidVisitId || inputVisitId == 0)
	{
		cout << "Please enter visit id (or " << HELP << " to print all visits): ";
		inputVisitId = getIntegerFromUser(1);
		if (inputVisitId == HELP)
			printAllVisits();
		else
			visit = HospitalManager::getInstance()->getConstVisitById(inputVisitId);
		if (visit == nullptr) 
		{
			invalidVisitId = true;
			cout << "Invalid visit id" << endl;
		}
		else
			invalidVisitId = false;
	}

	if (visit == nullptr)
		return HospitalManager::getInstance()->getConstVisitById(visitId);
	return visit;
}
const Patient* HospitalController::getPatientFromUser(int patientId) const
{
	if (HospitalManager::getInstance()->getCurrectNumOfPatients() == 0)
	{
		cout << "No patients found." << endl;
		return nullptr;
	}
	bool invalidPatientId = false;
	const Patient* patient = nullptr;
	int inputPatientId = patientId;

	while (invalidPatientId || inputPatientId == 0)
	{
		cout << "Please enter patient id: (or " << HELP << " to print all patients) ";
		inputPatientId = getIntegerFromUser(1);
		if (inputPatientId == HELP)
			printAllPatients();
		else
			patient = HospitalManager::getInstance()->getConstPatientById(inputPatientId);
		if (patient == nullptr) 
		{
			invalidPatientId = true;
			cout << "Invalid patient id" << endl;
		}
		else
			invalidPatientId = false;
	}

	if (patient == nullptr)
		return HospitalManager::getInstance()->getConstPatientById(patientId);
	return patient;
}
const Doctor* HospitalController::getDoctorFromUser(int doctorId) const
{
	if (HospitalManager::getInstance()->getCurrentNumOfDoctors() == 0)
	{
		cout << "No Doctors found." << endl;
		return nullptr;
	}
	const Employee* doctor = getEmployeeFromUser(doctorId, typeid(Doctor).name());
	if (doctor != nullptr)
		return dynamic_cast<const Doctor*>(doctor);
	return nullptr;
}
const Nurse* HospitalController::getNurseFromUser(int nurseId) const
{
	if (HospitalManager::getInstance()->getCurrentNumOfNurses() == 0)
	{
		cout << "No Nurses found." << endl;
		return nullptr;
	}
	const Employee* nurse = getEmployeeFromUser(nurseId, typeid(Nurse).name());
	if (nurse != nullptr)
		return dynamic_cast<const Nurse*>(nurse);
	return nullptr;
}
const Researcher* HospitalController::getResearcherFromUser(int researcherId) const
{
	if (HospitalManager::getInstance()->getCurrentNumOfResearchers() == 0)
	{
		cout << "No Researchers found." << endl;
		return nullptr;
	}
	const Employee* researcher = getEmployeeFromUser(researcherId, typeid(Researcher).name());
	if (researcher != nullptr)
		return dynamic_cast<const Researcher*>(researcher);
	return nullptr;
}
const Surgeon* HospitalController::getSurgeonFromUser(int surgeonId) const
{
	if (HospitalManager::getInstance()->getCurrentNumOfSurgeons() == 0)
	{
		cout << "No Surgeons found." << endl;
		return nullptr;
	}
	const Employee* surgeon = getEmployeeFromUser(surgeonId, typeid(Surgeon).name());
	if (surgeon != nullptr)
		return dynamic_cast<const Surgeon*>(surgeon);
	return nullptr;
}
const ResearchingDoctor* HospitalController::getResearchingDoctorFromUser(int researchingDoctorId) const
{
	if (HospitalManager::getInstance()->getCurrentNumOfResearchers() == 0)
	{
		cout << "No ResearchingDoctors found." << endl;
		return nullptr;
	}
	const Employee* researchingDoctor = getEmployeeFromUser(researchingDoctorId, typeid(ResearchingDoctor).name());
	if (researchingDoctor != nullptr)
		return dynamic_cast<const ResearchingDoctor*>(researchingDoctor);
	return nullptr;
}
const CareGivingEmployee* HospitalController::getCareGivingEmployeeFromUser(int careGivingEmployeeId) const
{
	cout << "Please select care giving employee type: " << endl;
	cout << "\t" << EMPLOYEE_TYPE_DOCTOR << ". Select doctor." << endl;
	cout << "\t" << EMPLOYEE_TYPE_NURSE << ". Select nurse." << endl;
	cout << "\t" << EMPLOYEE_TYPE_SURGEON << ". Select surgeon." << endl;
	cout << "\t" << EMPLOYEE_TYPE_REASERCHING_DOCTOR << ". Select researching doctor." << endl;
	cout << HospitalController::PRESS_TO_GO_BACK << endl;
	switch (getIntegerFromUser())
	{
	case EMPLOYEE_TYPE_DOCTOR:
		return getDoctorFromUser(careGivingEmployeeId);
		break;
	case EMPLOYEE_TYPE_NURSE:
		return getNurseFromUser(careGivingEmployeeId);
		break;
	case EMPLOYEE_TYPE_SURGEON:
		return getSurgeonFromUser(careGivingEmployeeId);
		break;
	case EMPLOYEE_TYPE_REASERCHING_DOCTOR:
		return getResearchingDoctorFromUser(careGivingEmployeeId);
		break;
	default:
		return nullptr;
		break;
	}
}
const Department* HospitalController::getDepartmentFromUser(const char* departmentName) const
{
	if (HospitalManager::getInstance()->getCurrectNumOfDepartments() == 0)
	{
		cout << "No departments found" << endl;
		return nullptr;
	}

	bool invalidDepartmentName = true;
	const Department* department = nullptr;

	if (departmentName == nullptr)
	{
		char* inputDepartmentName = new char[MAX_STRING_SIZE];
		while (invalidDepartmentName)
		{
			cout << "Please enter department name (or " << HELP << " to print all departments): ";
			getStringFromUser(inputDepartmentName);
			if (strcmp(inputDepartmentName, "-999") == 0)
				printAllDepartments();
			department = HospitalManager::getInstance()->getConstDepartmentByName(inputDepartmentName);
			if (department == nullptr) 
			{
				invalidDepartmentName = true;
				cout << "Invalid department name" << endl;
			}
			else
				invalidDepartmentName = false;
		}
		delete[] inputDepartmentName;
	}
	else {
		department = HospitalManager::getInstance()->getConstDepartmentByName(departmentName);
	}
	
	
	return department;
}
const Surgery* HospitalController::getSurgeryFromUser(int surgeryId) const
{
	if (HospitalManager::getInstance()->getCurrentNumOfSurgeries() == 0)
	{
		cout << "No Surgeries found." << endl;
		return nullptr;
	}
	const Surgery* surgery = nullptr;
	const Visit* temp;
	do 
	{
		temp = getVisitFromUser(surgeryId);
	} while (temp != nullptr && strcmp(typeid(Surgery).name(), typeid(*temp).name()) != 0);
	
	surgery = dynamic_cast<const Surgery*>(temp);
	return surgery;
}
const Employee* HospitalController::getEmployeeFromUser(int employeeId, const char* employeeClass) const
{
	if (HospitalManager::getInstance()->getCurrectNumOfEmployees() == 0)
	{
		cout << "No Employees found." << endl;
		return nullptr;
	}

	bool invalidEmployeeId = false;
	const Employee* employee = nullptr;
	int inputEmployeeId = employeeId;

	while (invalidEmployeeId || inputEmployeeId == 0)
	{
		cout << "Please enter "<< employeeClass+6 <<" id: (or " << HELP << " to print all employees) ";
		inputEmployeeId = getIntegerFromUser(1);
		if (inputEmployeeId == HELP)
			printAllEmployees();
		else {
			employee = HospitalManager::getInstance()->getConstEmployeeById(inputEmployeeId);
			if (strcmp(typeid(*employee).name(), employeeClass) != 0)
				employee = nullptr;
		}
			
		if (employee == nullptr)
		{
			invalidEmployeeId = true;
			cout << "Invalid " << employeeClass+6 << " id" << endl;
		}
		else
			invalidEmployeeId = false;
	}

	if (employee == nullptr) {
		employee = (Employee*)HospitalManager::getInstance()->getConstEmployeeById(employeeId);
		if (strcmp(typeid(*employee).name(), employeeClass) != 0)
			employee = nullptr;
	}

	return employee;
}
/* general methods */
/*
* A general function to get a string input from user
* @return char*
*/
char* HospitalController::getStringFromUser(char* outputBuffer) const
{
	char* buffer = outputBuffer;
	bool validString = true;
	// allocate new inputBuffer
	if(buffer == nullptr)
		buffer = new char[MAX_STRING_SIZE];

	do
	{
		cin.getline(buffer, MAX_STRING_SIZE);
		validString = validateString(buffer);
		if (!validString)
			cout << HospitalController::INVALID_INPUT << endl;
	} while (!validString);
		
	return buffer;
}
int HospitalController::getIntegerFromUser(int minVal, int maxVal) const
{
	int result;
	cin.getline(inputBuffer, MAX_STRING_SIZE);
	result = atoi(inputBuffer);

	while ((result < minVal || result > maxVal ) && result != HELP)
	{
		cout << HospitalController::INVALID_INPUT << endl;
		cin.getline(inputBuffer, MAX_STRING_SIZE);
		result = atoi(inputBuffer);
	} 

	return result;
}
double HospitalController::getDoubleFromUser(double minVal, double maxVal) const
{
	double result;
	cin.getline(inputBuffer, MAX_STRING_SIZE);
	result = atoi(inputBuffer);

	while ((result < minVal || result > maxVal) && result != HELP)
	{
		cout << HospitalController::INVALID_INPUT << endl;
		cin.getline(inputBuffer, MAX_STRING_SIZE);
		result = atof(inputBuffer);
	}

	return result;
}
bool HospitalController::validateString(const char* str) const 
{
	if (!*str)
		return false;

	int size = static_cast<int>(strlen(str));
	char* temp = new char[size+1];
	char* cpy = temp;

	while (*str) 
	{
		if (*str == ' ') 
			str++;
		else 
			*cpy++ = *str++;
	}
	*cpy = '\0';

	if (strlen(temp) == 0)
	{
		delete[] temp;
		return false;
	}

	delete[] temp;
	return true;
}

const char* HospitalController::PRESS_TO_GO_BACK	= "Press any other key to go back to previous menu.";
const char* HospitalController::INVALID_INPUT		= "Invalid Input.";