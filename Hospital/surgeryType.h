#ifndef surgeryType_h
#define surgeryType_h

class SurgeryType
{
protected:
    char* name;
    int durationMin;
    float precentageOfSuccess;
    int maxNumOfSurgeons;
public:
	SurgeryType(const char *name, int durationMin, float precentageOfSuccess, int maxNumOfSurgeons);
	SurgeryType(const SurgeryType& surgeryType);

	~SurgeryType();

    const char* getName()			const;
	int getDurationMin()			const;
	float getPrecentageOfSuccess()	const;
	int getMaxNumOfSurgeons()       const;

	void setName(const char *name);
    void setDurationMin(int durationMin);
    void setPrecentageOfSuccess(float precentageOfSuccess);
    void setMaxNumOfSurgeons(int maxNumOfSurgeons);
};
#endif /* surgeryType_h */
