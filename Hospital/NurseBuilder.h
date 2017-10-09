#pragma once
#ifndef NURSE_BUILDER_H
#define NURSE_BUILDER_H
#include "IEmployeeBuilder.h"
#include "nurse.h"
class NurseBuilder : public IEmployeeBuilder
{
public:
	virtual Nurse* build() override;
};

#endif // !DOCTOR_BUILDER_H
