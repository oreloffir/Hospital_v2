#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include "visit.h"
#include "person.h"
#include <iostream>

class Patient : public Person
{
public:
	static constexpr int MAX_NUMBER_OF_ALLERGIES	= 20;
	static constexpr int MAX_NUMBER_OF_VISITS		= 30;

    Patient(int id, const char* name, const char* dateOfBirth, eGender gender);
    Patient(const Patient& other)			 = delete;
    Patient& operator=(const Patient& other) = delete;

    virtual ~Patient();

    void visitHospital(const char* date);
    bool anesthetize(const char* date);

	void addVisit(const Visit* visit);
    void setLastDateVisited(const char* lastDateVisited);
    void setLastDateAnesthetized(const char* lastDateAnesthetized);
	bool addAllergie(const char* nameOfAllergie);

	int getNumOfVisits()					const;
	int getNumOfAllergies()					const;
	const Visit* const* getVisits()			const;
	const char* getLastDateVisited()		const;
	const char* getLastDateAnesthetized()	const;

	void printVisits() const;
	virtual void toOs(std::ostream& os) const override;

protected:
    Visit const* *	visits;
    const char*		lastDateVisited;
	const char*		lastDateAnesthetized;
    char**			allergies;
	int				numOfAllergies;
	int				numOfVisits;
};

#endif // PATIENT_H_INCLUDED
