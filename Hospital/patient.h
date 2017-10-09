#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include "visit.h"
#include "person.h"
#include <iostream>
#include <string>
using namespace std;

class Patient : public Person
{
public:
	static constexpr int MAX_NUMBER_OF_ALLERGIES	= 20;
	static constexpr int MAX_NUMBER_OF_VISITS		= 30;

    Patient(int id, const string name, const string dateOfBirth, eGender gender);
    Patient(const Patient& other)			 = delete;
    Patient& operator=(const Patient& other) = delete;

    virtual ~Patient();

    void visitHospital(const string date);
    bool anesthetize(const string date);

	void addVisit(const Visit* visit);
    void setLastDateVisited(const string lastDateVisited);
    void setLastDateAnesthetized(const string lastDateAnesthetized);
	bool addAllergie(const string nameOfAllergie);

	int getNumOfVisits()					const;
	int getNumOfAllergies()					const;
	const Visit* const* getVisits()			const;
	const string getLastDateVisited()		const;
	const string getLastDateAnesthetized()	const;

	void printVisits() const;
	virtual void toOs(std::ostream& os) const override;

protected:
    Visit const* *	visits;
    string		lastDateVisited; //TODO check const
	string		lastDateAnesthetized;
    string*			allergies;
	int				numOfAllergies;
	int				numOfVisits;
};

#endif // PATIENT_H_INCLUDED
