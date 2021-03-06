#ifndef surgeryType_h
#define surgeryType_h
#include <string>
using namespace std;

class SurgeryType
{
protected:
    string name;
    int durationMin;
    float precentageOfSuccess;
    int maxNumOfSurgeons;
public:
	SurgeryType(const string& name, int durationMin, float precentageOfSuccess, int maxNumOfSurgeons)
		:durationMin(durationMin), 
		precentageOfSuccess(precentageOfSuccess), 
		maxNumOfSurgeons(maxNumOfSurgeons),
		name(name) {};
	
	SurgeryType(const SurgeryType& surgeryType)
		: name(surgeryType.name),
		durationMin(surgeryType.durationMin),
		precentageOfSuccess(surgeryType.precentageOfSuccess),
		maxNumOfSurgeons(surgeryType.maxNumOfSurgeons) {};

    const string& getName()			const;
	int getDurationMin()			const;
	float getPrecentageOfSuccess()	const;
	int getMaxNumOfSurgeons()       const;

	void setName(const string& name);
    void setDurationMin(int durationMin);
    void setPrecentageOfSuccess(float precentageOfSuccess);
    void setMaxNumOfSurgeons(int maxNumOfSurgeons);
};
#endif /* surgeryType_h */
