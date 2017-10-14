#include "person.h"

Person::Person(const Person& other)
{
	*this = other;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		id			= other.id;
		gender		= other.gender;
		name		= other.name;
		dateOfBirth	= other.dateOfBirth;
	}
	return *this;
}

int Person::getId() const
{
	return id;
}
const string& Person::getName() const
{
	return name;
}
const string& Person::getDateOfBirth() const
{
	return dateOfBirth;
}
Person::eGender Person::getGender() const
{
	return gender;
}
const string& Person::getGenderName() const
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

const string Person::genders[] = { "MALE", "FEMALE" };