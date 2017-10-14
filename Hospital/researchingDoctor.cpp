#include "researchingDoctor.h"

int ResearchingDoctor::getMaxNumOfTestSubjects() const
{
	return this->maxNumOfTestSubjects;
}
int ResearchingDoctor::getCurrentNumOfTestSubjects() const
{
	return (int)testSubjects.size();
}
const vector<const Patient*> ResearchingDoctor::getTestSubjects() const
{
	return this->testSubjects;
}

void ResearchingDoctor::addTestSubject(const Patient& testSubject)
{
	testSubjects.push_back(&testSubject);
}
void ResearchingDoctor::removeTestSubject(const Patient& testSubject)
{
	bool found = false;
	vector<const Patient*>::const_iterator itr		= testSubjects.begin();
	vector<const Patient*>::const_iterator itrEnd	= testSubjects.end();
	for (itr; itr != itrEnd; itr++)
		if ((*itr)->getId() == testSubject.getId())
		{
			found = true;
			break;
		}
	if (!found) return;
	testSubjects.erase(itr);
}

void ResearchingDoctor::operator+=(const Patient& testSubject)
{
	this->addTestSubject(testSubject);
}
void ResearchingDoctor::operator-=(const Patient& testSubject)
{
	this->removeTestSubject(testSubject);
}

void ResearchingDoctor::work() const
{
	Researcher::work();
	Doctor::work();
}
void ResearchingDoctor::toOs(ostream& os) const
{
	Doctor::toOs(os);
	os << "-----------Researcher Details-----------" << endl;
	os << "Area Of Research: " << this->getAreaOfResearch() << endl;
	os << "-----------ResearchingDoctor Details-----------" << endl;
	os << "Num Of Test Subjects: ";

	if (testSubjects.size() == 0)
		os << " No Subjects." << endl;
	else {
		os << testSubjects.size() << endl;
		for (int i = 0; i < testSubjects.size(); i++)
			os << "\t name: " << testSubjects[i]->getName() <<" id: " << testSubjects[i]->getId() << endl;
	}
}