#ifndef RESEARCHER_H_INCLUDED
#define RESEARCHER_H_INCLUDED

#include "employee.h"
#include <iostream>
using namespace std;

class Researcher : virtual public Employee
{
public:
	static int constexpr MAX_NUMBER_OF_PUBLICATIONS = 20;
	Researcher(int id, const char* name, const char* dateOfBirth, eGender gender,
		const char* startWorkingDate, eRank employeeRank, double salary,
		const char* areaOfTraining, float seniorityYears, const char* areaOfResearch);
	Researcher(const Employee& employee, const char* areaOfResearch);
	Researcher(const Researcher& other);
	virtual ~Researcher();

	const Researcher& operator=(const Researcher& other);

	int getNumOfPublications()					const;
	const char*	const getAreaOfResearch()		const;
	const char* const* getPublicationsNames()	const;

	bool addPublicationName(const char* publicationName);
	void operator+=(const char* publication);

	virtual void work()				const override;
	virtual void toOs(ostream& os)	const override;

protected:
	int numOfPublications;
	char* areaOfResearch;
	char** publicationsNames;

	void free();
};

#endif // RESEARCHER_H_INCLUDED
