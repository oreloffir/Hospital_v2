#pragma once
#include "surgeryType.h"
#include <iostream>
using namespace std;

SurgeryType::SurgeryType(const string& name, int durationMin, float precentageOfSuccess, int maxNumOfSurgeons = 1)
	: durationMin(durationMin), precentageOfSuccess(precentageOfSuccess), maxNumOfSurgeons(maxNumOfSurgeons)
{
	this->name = name;
	cout << "In SurgeryType::SurgeryType (name=" << this->name << ")" << endl;
}
SurgeryType::SurgeryType(const SurgeryType& surgeryType)
{
	name = surgeryType.name;
	durationMin = surgeryType.durationMin;
	precentageOfSuccess = surgeryType.precentageOfSuccess;
	maxNumOfSurgeons = surgeryType.maxNumOfSurgeons;
	cout << "In SurgeryType::SurgeryType(copy) (name=" << name << ")" << endl;
}
SurgeryType::~SurgeryType()
{
	cout << "In SurgeryType::~SurgeryType (name=" << name << ")" << endl;
}

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
	//delete[] name;
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

