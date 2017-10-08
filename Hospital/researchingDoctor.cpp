#include "researchingDoctor.h"

ResearchingDoctor::ResearchingDoctor(const Researcher& researcher, const Doctor& doctor,
	int maxNumOfTestSubjects)
	:Employee(researcher), Researcher(researcher), Doctor(doctor)
{
	std::cout << "In ResearchingDoctor::ResearchingDoctor()" << "---->" << this->name << std::endl;
	this->maxNumOfTestSubjects = maxNumOfTestSubjects;
	this->currentNumOfTestSubjects = 0;
	this->testSubjects = new const Patient*[maxNumOfTestSubjects];
}

ResearchingDoctor::~ResearchingDoctor()
{
	std::cout << "In ResearchingDoctor::~ResearchingDoctor()" << "---->" << this->name << std::endl;
	this->free();
}

int ResearchingDoctor::getMaxNumOfTestSubjects() const
{
	return this->maxNumOfTestSubjects;
}
int ResearchingDoctor::getCurrentNumOfTestSubjects() const
{
	return this->currentNumOfTestSubjects;
}
const Patient** ResearchingDoctor::getTestSubjects() const
{
	return this->testSubjects;
}

void ResearchingDoctor::work() const
{
	Researcher::work();
	Doctor::work();
}

void ResearchingDoctor::setMaxNumOfTestSubjects(int maxNumOfTestSubjects)
{

}

void ResearchingDoctor::addTestSubject(const Patient& testSubject)
{
	if (currentNumOfTestSubjects == maxNumOfTestSubjects) return; // TODO: throw exeption!
	testSubjects[currentNumOfTestSubjects] = &testSubject;
	++currentNumOfTestSubjects;
}

void ResearchingDoctor::removeTestSubject(const Patient& testSubject)
{
	int pos = -1;
	for (int i = 0; i < this->currentNumOfTestSubjects; i++)
		if (&testSubject == testSubjects[i])
		{
			pos = i;
			break;
		}
	if (pos < 0) return;
	if (pos == maxNumOfTestSubjects - 1)
	{
		testSubjects[pos] = nullptr;
		--currentNumOfTestSubjects;
		return;
	}
	for (int i = pos; i < this->currentNumOfTestSubjects && i < maxNumOfTestSubjects - 1; i++)
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

void ResearchingDoctor::free()
{
	delete[] testSubjects;
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