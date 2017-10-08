#ifndef	_EMPLOYEE_LISTENER_H
#define	_EMPLOYEE_LISTENER_H

class Employee;

class EmployeeListener
{
public:
	virtual ~EmployeeListener() {};
	virtual void onEmployeeRemoved(int employeeId) = 0;
	virtual void onEmployeeReplaced(const Employee* newPointer) = 0;
};
#endif // ! _EMPLOYEE_LISTENER
