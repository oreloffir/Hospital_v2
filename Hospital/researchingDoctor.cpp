#include "researchingDoctor.h"

ResearchingDoctor::ResearchingDoctor(const Researcher& researcher, const Doctor& doctor,
	int maxNumOfTestSubjects)
	:Employee(researcher), Researcher(researcher), Doctor(doctor)
{
	std::cout << "In ResearchingDoctor::ResearchingDoctor()" << "---->" << this->name << std::endl;
	this->maxNumOfTestSubjects = maxNumOfTestSubjects;
	this->currentNumOfTestSubjects = 0;
}

ResearchingDoctor::~ResearchingDoctor()
{
	std::cout << "In ResearchingDoctor::~ResearchingDoctor()" << "---->" << this->name << std::endl;
}

int ResearchingDoctor::getMaxNumOfTestSubjects() const
{
	return this->maxNumOfTestSubjects;
}
int ResearchingDoctor::getCurrentNumOfTestSubjects() const
{
	return this->currentNumOfTestSubjects;
}
const vector<const Patient*> ResearchingDoctor::getTestSubjects() const
{
	return this->testSubjects;
}
void ResearchingDoctor::printTestSubjects() const
{
	cout << "================= " << name << " test subjects =================" << endl;
	if (currentNumOfTestSubjects == 0)
		cout << "\t - Researcher doctor has no test subjects yet." << endl;
	else {
		vector<const Patient*>::const_iterator itr = testSubjects.begin();
		vector<const Patient*>::const_iterator itrEnd = testSubjects.end();
		for (; itr != itrEnd; itr++)
			cout << *(*itr) << endl;
	}
}

void ResearchingDoctor::addTestSubject(const Patient& testSubject)
{
	testSubjects.push_back(&testSubject);
	++currentNumOfTestSubjects;
}
void ResearchingDoctor::removeTestSubject(const Patient& testSubject)
{

	int pos = -1;
	vector<const Patient*>::const_iterator itr = testSubjects.begin();
	vector<const Patient*>::const_iterator itrEnd = testSubjects.end();
	for (int i = 0; itr != itrEnd; itr++, i++)
		if (*(itr) == &testSubject)
		{
			pos = i;
			break;
		}

	if (pos < 0) return;
	if (pos == maxNumOfTestSubjects - 1)
	{
		testSubjects.erase(testSubjects.begin() + pos);
		--currentNumOfTestSubjects;
		return;
	}

	if (testSubjects.capacity() <= currentNumOfTestSubjects)
		testSubjects.resize(currentNumOfTestSubjects * 2);
	for (int i = pos; i < this->currentNumOfTestSubjects; i++)
		testSubjects[i] = testSubjects[i + 1];
	--currentNumOfTestSubjects;
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

	if (currentNumOfTestSubjects == 0)
		os << " No Subjects." << endl;
	else {
		os << currentNumOfTestSubjects << endl;
		for (int i = 0; i < currentNumOfTestSubjects; i++)
			os << "\t name: " << testSubjects[i]->getName() <<" id: " << testSubjects[i]->getId() << endl;
	}
}