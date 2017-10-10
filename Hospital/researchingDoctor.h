#ifndef RESEARCHING_DOCTOR_H_INCLUDED
#define RESEARCHING_DOCTOR_H_INCLUDED


#include "doctor.h"
#include "patient.h"
#include "researcher.h"

class ResearchingDoctor : public Researcher, public Doctor
{
public:
	ResearchingDoctor(const Researcher& researcher, const Doctor& doctor, int maxNumOfTestSubjects);
	ResearchingDoctor(const ResearchingDoctor& other) = delete;
	ResearchingDoctor& operator=(const ResearchingDoctor& other) = delete;
	virtual ~ResearchingDoctor();

	int getMaxNumOfTestSubjects()					const;
	int getCurrentNumOfTestSubjects()				const;
	const vector<const Patient*> getTestSubjects()	const;
	void printTestSubjects()						const;

	void addTestSubject(const Patient& testSubject);
	void removeTestSubject(const Patient& testSubject);

	void work() const override;
	virtual void toOs(std::ostream& os) const override;

	void operator+=(const Patient& testSubject);
	void operator-=(const Patient& testSubject);

protected:
	int maxNumOfTestSubjects;
	int currentNumOfTestSubjects;
	vector<const Patient*> testSubjects;
};

#endif // RESEARCHING_DOCTOR_H_INCLUDED
