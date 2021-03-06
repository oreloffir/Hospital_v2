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

	Patient(int id, const string& name, const string& dateOfBirth, eGender gender)
		: Person(id, name, dateOfBirth, gender) {};

    Patient(const Patient& other)			 = delete;
    Patient& operator=(const Patient& other) = delete;

    void visitHospital(const string& date);
    bool anesthetize(const string& date);

	void addVisit(const Visit* visit);
    void setLastDateVisited(const string& lastDateVisited);
    void setLastDateAnesthetized(const string& lastDateAnesthetized);
	bool addAllergie(const string& nameOfAllergie);

	int getNumOfVisits()					const;
	int getNumOfAllergies()					const;
	const vector<const Visit*> getVisits()	const;
	const string& getLastDateVisited()		const;
	const string& getLastDateAnesthetized()	const;

	void printVisits() const;
	virtual void toOs(std::ostream& os) const override;

protected:
    vector<const Visit*>	visits;
	vector<string>			allergies;
    string					lastDateVisited;
	string					lastDateAnesthetized;
};
#endif // PATIENT_H_INCLUDED
