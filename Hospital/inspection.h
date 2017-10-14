#ifndef inspection_h
#define inspection_h
#include "visit.h"

class Doctor;

class Inspection: public Visit
{
public:
	static const string labResults[];
    enum eLabResult {POSITIVE, NEGETIVE};
    
	Inspection(const Visit::VisitInfo visitInfo, const string& typeOfInspection)
		:Visit(visitInfo.date, visitInfo.cause, visitInfo.department, visitInfo.patient, visitInfo.typeOfCare),
		typeOfInspection(typeOfInspection) {};
	
	Inspection(const Inspection& other)						= delete;
    const Inspection& operator=(const Inspection& other)	= delete;

    const string getTypeOfInspection()	const;
    eLabResult getLabResult()			const;
	const string getLabResultName()		const;

	void setTypeOfInspection(const string typeOfInspection);
    void setLabResult(eLabResult labResult);

	void toOs(std::ostream& os) const override;

protected:
    string typeOfInspection;
    eLabResult labResult;
};
#endif /* inspection_h */
