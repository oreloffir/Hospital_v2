#ifndef RESEARCHER_H_INCLUDED
#define RESEARCHER_H_INCLUDED
#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

class Researcher : virtual public Employee
{
public:
	Researcher(int id, const string& name, const string& dateOfBirth, eGender gender,
		const string& startWorkingDate, eRank employeeRank, double salary,
		const string& areaOfTraining, float seniorityYears, const string& areaOfResearch)
		:Employee(id, name, dateOfBirth, gender, startWorkingDate, employeeRank, salary, areaOfTraining, seniorityYears),
		areaOfResearch(areaOfResearch) {};
	Researcher(const Employee& employee, const string& areaOfResearch)
		:Employee(employee),
		areaOfResearch(areaOfResearch) {};
	
	virtual ~Researcher() {};

	Researcher(const Researcher& other);
	const Researcher& operator=(const Researcher& other);

	int getNumOfPublications()					const;
	const string& getAreaOfResearch()			const;
	const vector<string> getPublicationsNames()	const;

	bool addPublicationName(const string publicationName);
	void operator+=(const string publication);

	virtual void work()				const override;
	virtual void toOs(ostream& os)	const override;

protected:
	string areaOfResearch;
	vector<string> publicationsNames;
};
#endif // RESEARCHER_H_INCLUDED
