#ifndef _SURGERY_H
#define _SURGERY_H
#include "visit.h"
#include "surgeryType.h"
#include <string>
#include <iostream>
using namespace std;

class Surgery: public Visit
{
public:
	static const string surgeryKind[];
	static constexpr int NUMBER_OF_TYPES = 4;
    enum eSurgeryKind {EASY, NORMAL, HARD, LIFE_SAVING};
    
    //ctors
    Surgery(const Visit::VisitInfo visitInfo, const SurgeryType& type, int numOfSurgeons = 1);
    //getters
    const SurgeryType* getSurgeryType() const;
	const string& getSurgeryKindName()	const;
	eSurgeryKind getSurgeryKind()		const;
    int getNumOfSurgeons()				const;
    int getDurationMin()				const;
	bool getIsDone()					const;
	bool getSuccsesfullSurgery()		const;
    
    //setters
    void setNumOfSurgeons(int numOfSurgeons);
    void setDurationMin(int duration);
	void surgeryDone(bool result);

	void toOs(std::ostream& os) const override;
    
private:
    eSurgeryKind kind;
    SurgeryType type;
    int actualNumOfSurgeons;
    int actualDurationMin;
	bool isDone;
	bool succsesfullSurgery;
};


#endif /* _SURGERY_H */
