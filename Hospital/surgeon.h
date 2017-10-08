#ifndef SURGEON_H_INCLUDED
#define SURGEON_H_INCLUDED

#include "doctor.h"
#include "patient.h"
#include "surgery.h"

class Surgeon : public Doctor
{
public:
	Surgeon(const Doctor& doctor, bool hasSecurityClearance, int numOfSuccesfulSurgeries = 0, int numOfSurgeries = 0);

	Surgeon(const Surgeon& other) = delete;

	virtual ~Surgeon();

	bool hasSecurityClearance()						const;
	int getNumOfSuccesfullSurgeries()				const;
	float getSurgeryChances(const Surgery* surgery)	const;
	bool performSurgery(const Surgery* surgery);

	virtual void toOs(std::ostream& os) const override;

protected:
	bool securityClearance;
	int numOfSuccesfullSurgeries;
	int numOfSurgeries;
};

#endif // SURGEON_H_INCLUDED