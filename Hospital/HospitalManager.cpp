#include "HospitalManager.h"
#include "patient.h"
#include <iostream>
using namespace std;

HospitalManager::HospitalManager()
{
	currentNumOfSurgeries	= 0;
	currentNumOfDoctors		= 0;
	currentNumOfNurses		= 0;
	currentNumOfResearchers = 0;
	currentNumOfSurgeons	= 0;
}
HospitalManager::~HospitalManager()
{
	int i;
	for (i = 0; i < departments.size(); i++)
		delete departments[i];
	for (i = 0; i < patients.size(); i++)
		delete patients[i];
	for (i = 0; i < visits.size(); i++)
		delete visits[i];
	for (i = 0; i < employees.size(); i++)
		delete employees[i];
}
HospitalManager * HospitalManager::getInstance()
{
	if (instance == nullptr)
		instance = new HospitalManager();
	return instance;
}

/* get entities - private functions*/
Employee* HospitalManager::getEmployeeById(int employeeId) const
{
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == employeeId)
			return employees[i];
	return nullptr;
}
Doctor* HospitalManager::getDoctorById(int doctorId) const
{
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == doctorId)
			return dynamic_cast<Doctor*>(employees[i]);
	return nullptr;
}
Nurse* HospitalManager::getNurseById(int nurseId) const
{
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == nurseId)
			return dynamic_cast<Nurse*>(employees[i]);
	return nullptr;
}
Researcher* HospitalManager::getResercherById(int resercherId) const
{
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == resercherId)
			return dynamic_cast<Researcher*>(employees[i]);
	return nullptr;
}
ResearchingDoctor* HospitalManager::getResearchingDoctorById(int reserchingDoctorId) const
{
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == reserchingDoctorId && strcmp(typeid(ResearchingDoctor).name(), typeid(*employees[i]).name()) == 0)
			return dynamic_cast<ResearchingDoctor*>(employees[i]);
	return nullptr;
}
Surgeon* HospitalManager::getSurgeonById(int surgeonId) const
{
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == surgeonId && strcmp(typeid(Surgeon).name(), typeid(*employees[i]).name()) == 0)
			return dynamic_cast<Surgeon*>(employees[i]);
	return nullptr;
}
Department* HospitalManager::getDepartmentByName(const string& departmentName) const
{
	for (int i = 0; i < departments.size(); i++)
		if (departments[i]->getName().compare(departmentName) == 0)
			return departments[i];
	return nullptr;
}
Patient* HospitalManager::getPatientById(int patientId) const
{
	for (int i = 0; i < patients.size(); i++)
		if (patients[i]->getId() == patientId)
			return patients[i];
	return nullptr;
}

/*Department functions*/
const Department& HospitalManager::createDepartment(const string& departmentName) throw(const char*)
{
	Department* department = new Department(departmentName);
	departments.push_back(department);
	addEmployeeListener(department);
	return *department;

}
const Department* HospitalManager::getConstDepartmentByName(const string& departmentName) const
{
	return getDepartmentByName(departmentName);
}
const vector<const Department*> HospitalManager::getAllDepartments() const
{
	return vector<const Department*>(departments.begin(), departments.end());
}
int HospitalManager::getCurrectNumOfDepartments() const
{
	return (int)departments.size();
}
void HospitalManager::addPatientToDepartment(const Patient* patient, const Department* department)
{
	Department* myDepartment = getDepartmentByName(department->getName());
	*myDepartment += *patient;
}
void HospitalManager::removePatientFromDepartment(const Patient* patient, const Department* department)
{
	Department* myDepartment = getDepartmentByName(department->getName());
	*myDepartment -= *patient;
}
void HospitalManager::addEmployeeToDepartment(const Employee* employee, const Department* department)
{
	Department* myDepartment = getDepartmentByName(department->getName());
	Employee* myEmployee = getEmployeeById(employee->getEmployeeId());
	*myDepartment += *employee;
	myEmployee->addDepartment(myDepartment);
}
void HospitalManager::removeEmployeeFromDepartment(const Employee* employee, const Department* department)
{
	Department* myDepartment = getDepartmentByName(department->getName());
	Employee* myEmployee = getEmployeeById(employee->getEmployeeId());
	*myDepartment -= *employee;
	myEmployee->removeDepartment(myDepartment->getName());
}

/*Patient functions*/
const Patient& HospitalManager::createPatient(int id, const string& name, const string& dateOfBirth, Person::eGender gender) throw(const char*)
{
	Patient* patient = new Patient(id, name, dateOfBirth, gender);
	patients.push_back(patient);
	return *patient;
}
const Patient* HospitalManager::getConstPatientById(int patientId) const
{
	return getPatientById(patientId);
}
bool HospitalManager::addAllergieToPatient(int patientId, const string& allergieName)
{
	return getPatientById(patientId)->addAllergie(allergieName);

	return false;
}
const vector<const Patient*> HospitalManager::getAllPatients() const
{
	return vector<const Patient*>(patients.begin(), patients.end());
}
int HospitalManager::getCurrectNumOfPatients() const
{
	return (int)patients.size();
}

/*Employee functions*/
int HospitalManager::getCurrectNumOfEmployees() const
{
	return (int)employees.size();
}
const vector<const Employee*> HospitalManager::getAllEmployees() const
{
	return vector<const Employee*>(employees.begin(), employees.end());
}
const Employee* HospitalManager::getConstEmployeeById(int employeeId) const
{
	return getEmployeeById(employeeId);
}
/*Doctor functions*/
const Doctor& HospitalManager::createDoctor(const Employee::employeeInfo employeeInfo, const string& fieldOfExpertise, int numOfDiplomas)
{
	DoctorBuilder doctorBuilder;

	doctorBuilder.setId(employeeInfo.id)
		.setName(employeeInfo.name)
		.setDateOfBirth(employeeInfo.dateOfBirth)
		.setGender(employeeInfo.gender)
		.setStartWorkingDate(employeeInfo.startWorkingDate)
		.setEmployeeRank(employeeInfo.employeeRank)
		.setSalary(employeeInfo.salary)
		.setAreaOfTraining(employeeInfo.areaOfTraining)
		.setSeniorityYears(employeeInfo.seniorityYears);

	doctorBuilder.setFieldOfExpertise(fieldOfExpertise)
		.setNumOfDiplomas(numOfDiplomas);

	Doctor* doctor = doctorBuilder.build();

	employees.push_back(doctor);
	++currentNumOfDoctors;

	return *doctor;
}
const Doctor* HospitalManager::getConstDoctorById(int id) const
{
	return getDoctorById(id);
}
void HospitalManager::addDiplomaToDoctor(int id)
{
	Doctor* doctor = getDoctorById(id);
	if (doctor == nullptr)
		return;
	++(*doctor);
}
int HospitalManager::getCurrentNumOfDoctors() const
{
	return currentNumOfDoctors;
}
/*Nurse functions*/

const Nurse& HospitalManager::createNurse(const Employee::employeeInfo employeeInfo, int maxNumOfDuties)
{
	NurseBuilder nurseBuilder;

	nurseBuilder.setId(employeeInfo.id)
		.setName(employeeInfo.name)
		.setDateOfBirth(employeeInfo.dateOfBirth)
		.setGender(employeeInfo.gender)
		.setStartWorkingDate(employeeInfo.startWorkingDate)
		.setEmployeeRank(employeeInfo.employeeRank)
		.setSalary(employeeInfo.salary)
		.setAreaOfTraining(employeeInfo.areaOfTraining)
		.setSeniorityYears(employeeInfo.seniorityYears);
	
	nurseBuilder.setMaxNumOfDuties(maxNumOfDuties);

	Nurse* nurse = nurseBuilder.build();

	employees.push_back(nurse);
	++currentNumOfNurses;

	return *nurse;
}
const Nurse* HospitalManager::getConstNurseById(int id) const
{
	return getNurseById(id);
}
void HospitalManager::addDuty(int id, const string& duty)
{
	Nurse* nurse = getNurseById(id);
	if (nurse == nullptr)
		return;
	nurse->addDuty(duty);
}
void HospitalManager::removeDuty(int id, const string& duty)
{
	Nurse* nurse = getNurseById(id);
	if (nurse == nullptr)
		return;
	nurse->removeDuty(duty);
}
void HospitalManager::setMaxNumOfDuties(int id, int max)
{
	Nurse* nurse = getNurseById(id);
	if (nurse == nullptr)
		return;
	nurse->setMaxNumOfDuties(max);
}
int HospitalManager::getCurrentNumOfNurses() const
{
	return currentNumOfNurses;
}
/*Researcher functions*/
const Researcher& HospitalManager::createResearcher(const Employee::employeeInfo employeeInfo, const string& areaOfResearch) throw(const char*)
{
	ResearcherBuilder researcherBuilder;
	researcherBuilder.setId(employeeInfo.id)
		.setName(employeeInfo.name)
		.setDateOfBirth(employeeInfo.dateOfBirth)
		.setGender(employeeInfo.gender)
		.setStartWorkingDate(employeeInfo.startWorkingDate)
		.setEmployeeRank(employeeInfo.employeeRank)
		.setSalary(employeeInfo.salary)
		.setAreaOfTraining(employeeInfo.areaOfTraining)
		.setSeniorityYears(employeeInfo.seniorityYears);
	researcherBuilder.setAreaOfResearch(areaOfResearch);

	Researcher* researcher = researcherBuilder.build();
  
	employees.push_back(researcher);
	++currentNumOfResearchers;

	return *researcher;
}
const Researcher* HospitalManager::getConstResearcherById(int id) const
{
	return getResercherById(id);
}
bool HospitalManager::addPublicationToResearcher(int researcherId, const string& publicationName)
{
	Researcher* researcher = getResercherById(researcherId);
	if (researcher == nullptr)
		return false;
	return researcher->addPublicationName(publicationName);
}
int HospitalManager::getCurrentNumOfResearchers() const
{
	return currentNumOfResearchers;
}
/*Surgeon functions*/
const Surgeon& HospitalManager::createSurgeon(const Doctor* doctor, bool hasSecurityClearance, int numOfSuccesfulSurgeries, int numOfSurgeries)
{
	int doctorIndx = -1;
	for (int i = 0; i < employees.size(); i++)
		if (employees[i]->getEmployeeId() == doctor->getEmployeeId() && strcmp(typeid(Doctor).name(), typeid(*employees[i]).name()) == 0)
		{
			doctorIndx = i;
			break;
		}

	Doctor* removeDoctor = dynamic_cast<Doctor*>(employees[doctorIndx]);
	Surgeon* mySurgeon = new Surgeon(*doctor, hasSecurityClearance);

	// update departments and visits about the change
	for (int i = 0; i < employeeListeners.size(); i++)
		employeeListeners[i]->onEmployeeReplaced(mySurgeon);
	
	// update employees array
	employees[doctorIndx] = mySurgeon;
	delete removeDoctor;
	++currentNumOfSurgeons;

	return *dynamic_cast<Surgeon*>(employees[doctorIndx]);
}
const Surgeon* HospitalManager::getConstSurgeonById(int id) const
{
	return getSurgeonById(id);
}
bool HospitalManager::performSurgery(const Surgeon* surgeon, const Surgery* surgery) const
{
	if (surgeon != nullptr)
	{
		Surgery* mySurgery = dynamic_cast<Surgery*>(getVisitById(surgery->getVisitId()));
		Surgeon* mySurgeon = dynamic_cast<Surgeon*>(getEmployeeById(surgeon->getEmployeeId()));
		mySurgery->surgeryDone(mySurgeon->performSurgery(mySurgery));
	}
	return false;
}
int HospitalManager::getCurrentNumOfSurgeons() const
{
	return currentNumOfSurgeons;
}
/*Researching Doctor functions*/
const ResearchingDoctor& HospitalManager::createResearchingDoctor(const Doctor* doctor, const string& areaOfResearch, int maxNumOfTestSubjects) throw(const char*)
{
	int doctorIndx;

	Researcher* researcher = new Researcher(*doctor, areaOfResearch);

	for (int j = 0; j < employees.size(); j++)
		if (employees[j]->getEmployeeId() == doctor->getEmployeeId())
		{
			doctorIndx = j;
			break;
		}

	Doctor* removeDoctor = dynamic_cast<Doctor*>(employees[doctorIndx]);

	ResearchingDoctor* researchingDoctor = new ResearchingDoctor(*researcher, *doctor, maxNumOfTestSubjects);

	employees[doctorIndx] = researchingDoctor;
	++currentNumOfResearchers;

	delete researcher;
	delete removeDoctor;
	return *researchingDoctor;
}
const ResearchingDoctor * HospitalManager::getConstResearchingDoctorById(int id) const
{
	return getResearchingDoctorById(id);
}
void HospitalManager::addTestSubjectToRD(int researcherId, const Patient* testSubject) const
{
	ResearchingDoctor* researchingDoctor = getResearchingDoctorById(researcherId);
	if (researchingDoctor == nullptr)
		return;
	researchingDoctor->addTestSubject(*testSubject);
}
void HospitalManager::removeTestSubjectToRD(int researcherId, const Patient* testSubject) const
{
	ResearchingDoctor* researchingDoctor = getResearchingDoctorById(researcherId);
	if (researchingDoctor == nullptr)
		return;
	researchingDoctor->removeTestSubject(*testSubject);
}

/*Visit functions*/
const Visit* HospitalManager::getConstVisitById(int visitId) const
{
	return getVisitById(visitId);
}
Visit* HospitalManager::getVisitById(int visitId) const
{
	for (int i = 0; i < visits.size(); i++)
		if (visits[i]->getVisitId() == visitId)
			return visits[i];
	return nullptr;
}
void HospitalManager::addCareGivingEmployeeToVisit(const CareGivingEmployee* cge, int visitId)
{
	if (cge == nullptr)
		return;

	Visit* visit = getVisitById(visitId);
	if (visit == nullptr)
		return;

	*visit += *cge;
}
void HospitalManager::removeCareGivingEmployeeToVisit(const CareGivingEmployee* cge, int visitId)
{
	if (cge == nullptr)
		return;

	Visit* visit = getVisitById(visitId);
	if (visit == nullptr)
		return;

	*visit -= *cge;
}
int HospitalManager::getCurrentNumOfSurgeries() const
{
	return currentNumOfSurgeries;
}
const vector<const Visit*> HospitalManager::getAllVisits() const
{
	return vector<const Visit*>(visits.begin(), visits.end());
}
int HospitalManager::getCurrectNumOfVisits() const
{
	return (int)visits.size();
}
/*Surgery functions*/
const Surgery& HospitalManager::createSurgery(const Visit::VisitInfo& visitInfo, SurgeryType* type, int numOfSurgeons) throw(const char*)
{
	Surgery* surgery = new Surgery(visitInfo, *type, numOfSurgeons);
	visits.push_back(surgery);
	addEmployeeListener(surgery);

	getPatientById(visitInfo.patient->getId())->addVisit(surgery);
	getDepartmentByName(visitInfo.department->getName())->addVisit(surgery);
	++currentNumOfSurgeries;

	return *surgery;
}
/*Inspection functions*/
const Inspection& HospitalManager::createInspection(const Visit::VisitInfo& visitInfo, string& typeOfInspection) throw(const char*)
{
	Inspection* inspection = new Inspection(visitInfo, typeOfInspection);
	visits.push_back(inspection);

	getPatientById(visitInfo.patient->getId())->addVisit(inspection);
	getDepartmentByName(visitInfo.department->getName())->addVisit(inspection);

	return *inspection;
}


void HospitalManager::addEmployeeListener(EmployeeListener * employeeListener)
{
	employeeListeners.push_back(employeeListener);
}
void HospitalManager::removeEmployeeListener(EmployeeListener * employeeListener)
{
	bool found = false;
	vector<EmployeeListener*>::const_iterator itr = employeeListeners.begin();
	vector<EmployeeListener*>::const_iterator itrEnd = employeeListeners.end();
	for (itr; itr != itrEnd; itr++)
		if ((*itr) == employeeListener)
		{
			found = true;
			break;
		}
	if (!found) return;
	employeeListeners.erase(itr);

}

const char* HospitalManager::ARRAY_MAX_SIZE = "Error: Maximum array size exceeded.";
HospitalManager* HospitalManager::instance = nullptr;
