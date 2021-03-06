#include "surgeon.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool Surgeon::hasSecurityClearance() const
{
	return securityClearance;
}

int Surgeon::getNumOfSuccesfullSurgeries() const
{
	return numOfSuccesfullSurgeries;
}

float Surgeon::getSurgeryChances(const Surgery* surgery) const {
	float surgeryHardness = ((float)(Surgery::NUMBER_OF_TYPES - (int)surgery->getSurgeryKind()) / (float)Surgery::NUMBER_OF_TYPES);

	float sergeonStatistics = 1;
	if (numOfSurgeries > 0)
		sergeonStatistics = (float)numOfSuccesfullSurgeries / (float)numOfSurgeries;

	return surgeryHardness * sergeonStatistics * 100;
}

bool Surgeon::performSurgery(const Surgery* surgery)
{
	float surgeryChanges = getSurgeryChances(surgery);

	srand((int)time(NULL));
	double lifeIsHard = rand() % 100; // generate random number 0 - 99

	++numOfSurgeries;
	if (lifeIsHard > surgeryChanges) {
		return false;
	}
	else {
		++numOfSuccesfullSurgeries;
		return true;
	}
}
void Surgeon::toOs(ostream& os) const
{
	Doctor::toOs(os);
	os << "-----------Surgeon Details-----------" << endl;
	os << "Security clearance: ";
	if (securityClearance)
		os << "yes";
	else
		os << "no"; 
	os << endl;
	os << "Number of surgeries: " << numOfSurgeries << endl;
	os << "Number of succesfull surgeries: " << numOfSuccesfullSurgeries << endl;
}


