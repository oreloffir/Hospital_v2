#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	enum eGender { MALE, FEMALE };
	static const string genders[];

	Person(int id, const string& name, const string& dateOfBirth, eGender gender)
		: id(id), gender(gender), name(name), dateOfBirth(dateOfBirth) {};
	virtual ~Person() {};

	Person(const Person& person);
	const Person& operator=(const Person& other);
	
	int getId()						const;
	const string& getName()			const;
	const string& getDateOfBirth()	const;
	eGender getGender()				const;
	const string& getGenderName()	const;

	virtual void toOs(std::ostream& os) const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);

protected:
	int id;
	string name;
	string dateOfBirth;
	eGender gender;
};
#endif // PERSON_H_INCLUDED
