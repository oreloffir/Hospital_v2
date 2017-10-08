#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>

class Person
{
public:
	enum eGender { MALE, FEMALE };
	static const char* genders[];

	Person(int id, const char* name, const char* dateOfBirth, eGender gender);
	Person(const Person& person);
	const Person& operator=(const Person& other);

	virtual ~Person();

	int getId()						const;
	const char* getName()			const;
	const char* getDateOfBirth()	const;
	eGender getGender()				const;
	const char* getGenderName()		const;

	virtual void toOs(std::ostream& os) const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);

protected:
	int id;
	char* name;
	char* dateOfBirth;
	eGender gender;
};
#endif // PERSON_H_INCLUDED
