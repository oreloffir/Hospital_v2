#pragma once
#include <iostream>
using namespace std;
#include "person.h"

Person::Person(int id, const char* name, const char* dateOfBirth, eGender gender)
	: id(id), gender(gender)
{
	cout << "In Person::Person (name=" << name << ")" << endl;
	this->name			= _strdup(name);
	this->dateOfBirth	= _strdup(dateOfBirth);
}


Person::Person(const Person& other)
{
	cout << "In Person::Person(copy) (name=" << other.name << ")" << endl;
	*this = other;
}

const Person& Person::operator=(const Person& other)
{
	cout << "In Person::operator= (name=" << other.name << ")" << endl;
	if (this != &other)
	{
		delete[]	name;
		delete[]	dateOfBirth;
		id			= other.id;
		gender		= other.gender;
		name		= _strdup(other.name);
		dateOfBirth	= _strdup(other.dateOfBirth);
	}
	return *this;
}

Person::~Person()
{
	cout << "In Person::~Person (name=" << name << ")" << endl;
	delete[] name;
	delete[] dateOfBirth;
}

int Person::getId() const
{
	return id;
}

const char* Person::getName() const
{
	return name;
}

const char* Person::getDateOfBirth() const
{
	return dateOfBirth;
}

Person::eGender Person::getGender() const
{
	return gender;
}

const char* Person::getGenderName() const
{
	return Person::genders[gender];
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << "-----------Personal Details----------" << endl;
	os << "Person Name: " << "\t\t" << person.getName() << endl;
	os << "Persoanl ID: " << "\t\t" << person.getId() << endl;
	os << "Gender: " << "\t\t" << person.getGenderName() << endl;
	os << "Date Of Birth:" << "\t\t" << person.getDateOfBirth() << endl;
	person.toOs(os);
	return os;
}

const char* Person::genders[] = { "MALE", "FEMALE" };