#pragma once
#include "surgeryType.h"
#include <iostream>
using namespace std;

const string& SurgeryType::getName() const
{
	return name;
}
float SurgeryType::getPrecentageOfSuccess() const
{
	return precentageOfSuccess;
}
int SurgeryType::getMaxNumOfSurgeons() const
{
	return maxNumOfSurgeons;
}
int SurgeryType::getDurationMin() const
{
	return durationMin;
}

void SurgeryType::setDurationMin(int durationMin)
{
	this->durationMin= durationMin;
}
void SurgeryType::setName(const string& name)
{
	this->name = name;
}
void SurgeryType::setPrecentageOfSuccess(float precentageOfSuccess)
{
	this->precentageOfSuccess = precentageOfSuccess;
}
void SurgeryType::setMaxNumOfSurgeons(int maxNumOfSurgeons)
{
	this->maxNumOfSurgeons = maxNumOfSurgeons;
}

