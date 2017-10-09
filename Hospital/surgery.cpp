#include "surgery.h"
#include <iostream>
using namespace std;

Surgery::Surgery(const Visit::VisitInfo visitInfo, const SurgeryType& type, int numOfSurgeons)
: Visit(visitInfo.date, visitInfo.cause, visitInfo.department, visitInfo.patient, visitInfo.typeOfCare),
	type(type),
	actualNumOfSurgeons(numOfSurgeons)
{
	cout << "In Surgery::Surgery (type=" << type.getName() << ")" << endl;
	isDone = false;
	double precentageOfSuccess = type.getPrecentageOfSuccess();
	if (precentageOfSuccess < 25.0)
		kind = LIFE_SAVING;
	else if (precentageOfSuccess < 50.0)
		kind = HARD;
	else if (precentageOfSuccess < 75.0)
		kind = NORMAL;
	else if (precentageOfSuccess < 100.0)
		kind = EASY;
}

const SurgeryType* Surgery::getSurgeryType() const
{
	return &type;
}
const string& Surgery::getSurgeryKindName() const
{
	return Surgery::surgeryKind[kind];
}
Surgery::eSurgeryKind Surgery::getSurgeryKind() const
{
	return kind;
}
int Surgery::getNumOfSurgeons() const
{
	return actualNumOfSurgeons;
}
int Surgery::getDurationMin() const
{
	return actualDurationMin;
}
bool Surgery::getIsDone() const
{
	return isDone;
}
bool Surgery::getSuccsesfullSurgery() const
{
	return succsesfullSurgery;
}

void Surgery::setNumOfSurgeons(int numOfSurgeons)
{
	this->actualNumOfSurgeons = numOfSurgeons;
}
void Surgery::setDurationMin(int duration)
{
	this->actualDurationMin = duration;
}
void Surgery::surgeryDone(bool result)
{
	if (!isDone)
	{
		isDone = true;
		succsesfullSurgery = result;
	}
}

void Surgery::toOs(std::ostream& os) const
{
	os << "Surgery Name: " << "\t\t\t" << getSurgeryType()->getName() << std::endl;
	os << "Surgery Kind: " << "\t\t\t" << getSurgeryKindName() << std::endl;
	os << "Surgery Duration: " << "\t\t" << getSurgeryType()->getDurationMin() << std::endl;
	os << "Surgery Precentage of succsess: " << getSurgeryType()->getPrecentageOfSuccess() << "%" << std::endl;
	os << "Surgery Result: ";
	if (isDone)
		if (succsesfullSurgery)
			os << "Done - Success!";
		else
			os << "Done - Failed!";
	else
		os << "Surgery didn't preformed yet";
	os << endl;
}

const string Surgery::surgeryKind[] = {"EASY", "NORMAL", "HARD", "LIFE_SAVING" };