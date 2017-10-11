#include "employee.h"


int Employee::employeeIdGenerator = 1;

Employee::Employee(int id, const string& name, const string& dateOfBirth, eGender gender,
	const string& startWorkingDate, eRank employeeRank, double salary,
	const string& areaOfTraining, float seniorityYears = 0)
	:Person(id, name, dateOfBirth, gender),
	startWorkingDate(startWorkingDate),
	areaOfTraining(areaOfTraining),
	salary(salary),
	employeeRank(employeeRank),
	seniorityYears(seniorityYears)
{
	std::cout << "In Employee::Employee" << "---->" << this->name << std::endl;
	this->employeeId = Employee::employeeIdGenerator;
	++Employee::employeeIdGenerator;
	this->departments = new const Department*[Employee::MAX_NUMBER_OF_DEPATRMENTS];
	this->numberOfDepatments = 0;
}

Employee::Employee(const Employee& other)
	:Person(other) {
	std::cout << "In Employee::Employee(copy)" << "---->" << this->name << std::endl;
	*this = other;
}
const Employee& Employee::operator=(const Employee& other)
{
	std::cout << "In Employee::operator=" << std::endl;
	if (this != &other)
	{
		//delete[] areaOfTraining; // TODO
		//delete[] startWorkingDate;
		delete[] departments;

		employeeId = other.employeeId;
		departments = new const Department*[MAX_NUMBER_OF_DEPATRMENTS];
		for (int i = 0; i < numberOfDepatments; i++)
			departments[i] = other.departments[i];
		startWorkingDate = other.startWorkingDate;
		employeeRank = other.employeeRank;
		salary = other.salary;
		areaOfTraining = other.areaOfTraining;
		seniorityYears = other.seniorityYears;
	}
	return *this;
}
Employee::~Employee()
{
	std::cout << "In Employee::~Employee" << "---->" << this->name << std::endl;
	//delete[] areaOfTraining; //TODO
	//delete[] startWorkingDate;
	delete[] departments;
}

int Employee::getEmployeeId() const
{
	return this->employeeId;
}
const Department* const* Employee::getDepartments() const
{
	return this->departments;
}
const string& Employee::getStartWorkingDate() const
{
	return this->startWorkingDate;
}
Employee::eRank Employee::getEmployeeRank() const
{
	return this->employeeRank;
}
float Employee::getSeniorityYears() const
{
	return this->seniorityYears;
}
double Employee::getSalary() const
{
	return this->salary;
}

void Employee::work() const
{
	std::cout << "working" << std::endl;
	return;
}

void Employee::setSalary(double salary)
{
	this->salary = salary;
}
void Employee::updateSenorityYear(float senorityYears)
{
	this->seniorityYears = senorityYears;
}
const string& Employee::getAreaOfTraining() const
{
	return areaOfTraining;
}
void Employee::addDepartment(const Department* department)
{
	if (department == nullptr)
		return;
	if (numberOfDepatments == MAX_NUMBER_OF_DEPATRMENTS)
		return;
	removeDepartment(department->getName());
	departments[numberOfDepatments] = department;
	++numberOfDepatments;
}
void Employee::removeDepartment(const string& departmentName)
{
	int pos = -1;
	for (int i = 0; i < this->numberOfDepatments; i++)
		if (departments[i]->getName().compare(departmentName) == 0)
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == numberOfDepatments - 1)
	{
		departments[pos] = nullptr;
		--numberOfDepatments;
		return;
	}
	for (int i = pos; i < this->numberOfDepatments && i < MAX_NUMBER_OF_DEPATRMENTS - 1; i++)
		departments[i] = departments[i + 1];
	--numberOfDepatments;
}

bool Employee::operator==(const Employee & other)
{
	if (this->getEmployeeId() == other.getEmployeeId())
		return true;

	return false;
}

void Employee::toOs(std::ostream& os) const
{
	os << "-----------Employee Details-----------" << std::endl;
	os << "Employee id: " << "\t\t" << employeeId << std::endl;
	os << "Start working date: " << "\t" << startWorkingDate << std::endl;
	os << "Area of training: " << "\t" << areaOfTraining << std::endl;
	os << "Seniority years: " << "\t" << seniorityYears << std::endl;
	os << "Salary: " << "\t\t" << salary << std::endl;
	os << "Number of departments: " << "\t" << numberOfDepatments << std::endl;
	os << "Departments: " << std::endl;
	for (int i = 0; i < numberOfDepatments; i++)
	{
		os << "\t" << departments[i]->getName() << std::endl;
	}
}