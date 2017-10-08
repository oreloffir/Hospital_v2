#ifndef inspection_h
#define inspection_h
#include "visit.h"

class Doctor;



class Inspection: public Visit
{
public:
	static const char* labResults[];
    enum eLabResult {POSITIVE, NEGETIVE};
    
    //ctors
    Inspection(const Visit::VisitInfo visitInfo, const char* typeOfInspection);
	Inspection(const Inspection& other) = delete;
    ~Inspection();

    const Inspection& operator=(const Inspection& other) = delete;

    const char* getTypeOfInspection()	const;
    eLabResult getLabResult()			const;
	const char* getLabResultName()		const;

	void setTypeOfInspection(const char* typeOfInspection);
    void setLabResult(eLabResult labResult);

	void toOs(std::ostream& os) const override;

protected:
    char* typeOfInspection;
    eLabResult labResult;
};

#endif /* inspection_h */
