#pragma once
#ifndef DOCTOR_BUILDER_H
#define DOCTOR_BUILDER_H
#include "IEmployeeBuilder.h"
#include "doctor.h"
class DoctorBuilder : public IEmployeeBuilder
{
private:
	string fieldOfExpertise;
	int numOfDiplomas;
public:
	virtual DoctorBuilder& setFieldOfExpertise(const string& fieldOfExpertise);
	virtual DoctorBuilder& setNumOfDiplomas(int numOfDiplomas);
	virtual Doctor* build() override;
};

#endif // !DOCTOR_BUILDER_H
