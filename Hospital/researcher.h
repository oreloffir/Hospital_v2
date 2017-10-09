#ifndef RESEARCHER_H_INCLUDED
#define RESEARCHER_H_INCLUDED
#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

class Researcher : virtual public Employee
{
public:
	static int constexpr MAX_NUMBER_OF_PUBLICATIONS = 20;
	Researcher(int id, const string name, const string dateOfBirth, eGender gender,
		const string startWorkingDate, eRank employeeRank, double salary,
		const string areaOfTraining, float seniorityYears, const string areaOfResearch);
	Researcher(const Employee& employee, const string areaOfResearch);
	Researcher(const Researcher& other);
	virtual ~Researcher();

	const Researcher& operator=(const Researcher& other);

	int getNumOfPublications()					const;
	const string getAreaOfResearch()			const;
	const string const* getPublicationsNames()	const;

	bool addPublicationName(const string publicationName);
	void operator+=(const string publication);

	virtual void work()				const override;
	virtual void toOs(ostream& os)	const override;

protected:
	int numOfPublications;
	string areaOfResearch;
	string* publicationsNames;

	void free();
};

#endif // RESEARCHER_H_INCLUDED
