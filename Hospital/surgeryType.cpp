#pragma once
#include "surgeryType.h"
#include <iostream>
using namespace std;

SurgeryType::SurgeryType(const char *name, int durationMin, float precentageOfSuccess, int maxNumOfSurgeons = 1)
	: durationMin(durationMin), precentageOfSuccess(precentageOfSuccess), maxNumOfSurgeons(maxNumOfSurgeons)
{
	this->name = _strdup(name);
	cout << "In SurgeryType::SurgeryType (name=" << this->name << ")" << endl;
}

SurgeryType::SurgeryType(const SurgeryType & surgeryType)
{
	name = _strdup(surgeryType.name);
	durationMin = surgeryType.durationMin;
	precentageOfSuccess = surgeryType.precentageOfSuccess;
	maxNumOfSurgeons = surgeryType.maxNumOfSurgeons;
	cout << "In SurgeryType::SurgeryType(copy) (name=" << name << ")" << endl;
}

SurgeryType::~SurgeryType()
{
	cout << "In SurgeryType::~SurgeryType (name=" << name << ")" << endl;
	delete[]name;
}

const char* SurgeryType::getName() const
{
	return name;
}

void  SurgeryType::setName(const char *name)
{
	delete[] name;
	name = _strdup(name);
}

int  SurgeryType::getDurationMin() const
{
	return durationMin;
}

void  SurgeryType::setDurationMin(int durationMin)
{
	this->durationMin= durationMin;
}

float  SurgeryType::getPrecentageOfSuccess() const
{
	return precentageOfSuccess;
}

void  SurgeryType::setPrecentageOfSuccess(float precentageOfSuccess)
{
	this->precentageOfSuccess = precentageOfSuccess;
}

int  SurgeryType::getMaxNumOfSurgeons() const
{
	return maxNumOfSurgeons;
}

void  SurgeryType::setMaxNumOfSurgeons(int maxNumOfSurgeons)
{
	this->maxNumOfSurgeons = maxNumOfSurgeons;
}

