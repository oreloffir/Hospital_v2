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
		employeeId = other.employeeId;
		departments = other.departments; // TODO
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
}

int Employee::getEmployeeId() const
{
	return this->employeeId;
}
const vector<const Department*> Employee::getDepartments() const
{
	return this->departments;
}
const string& Employee::getStartWorkingDate() const
{
	return this->startWorkingDate;
}
const string& Employee::getAreaOfTraining() const
{
	return areaOfTraining;
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
void Employee::addDepartment(const Department* department)
{
	if (department == nullptr)
		return;
	removeDepartment(department->getName());
	departments.push_back(department);
	++numberOfDepatments;
}
void Employee::removeDepartment(const string& departmentName)
{
	int pos = -1;
	vector<const Department*>::const_iterator itr = departments.begin();
	vector<const Department*>::const_iterator itrEnd = departments.end();
	for (int i = 0; itr != itrEnd; itr++, i++)
		if ((*itr)->getName().compare(departmentName) == 0)
		{
			pos = i;
			break;
		}

	if (pos < 0) return;
	if (pos == numberOfDepatments - 1)
	{
		departments.erase(departments.begin() + pos);
		--numberOfDepatments;
		return;
	}
	if (departments.capacity() <= numberOfDepatments)
		departments.resize(numberOfDepatments * 2);
	for (int i = pos; i < this->numberOfDepatments; i++)
		departments[i] = departments[i + 1];
	--numberOfDepatments;
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