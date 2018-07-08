#include "person.h"

////////// Member functions //////////

Person::Person(string newName, int newAge, string newGender, int newHeight)
{
	mName = newName;
	mAge = newAge;
	mGender = newGender;
	mHeight = newHeight;
	cout << "Inside Person's constructor!" << endl;
}

Person::Person(const Person & copy)
{
	mName = copy.mName;
	mAge = copy.mAge;
	mGender = copy.mGender;
	mHeight = copy.mHeight;
}

Person::~Person()
{
	cout << "Inside of the Person's deconstructor" << endl;
}

Person & Person::operator=(const Person & rhs)
{
	if (this != &rhs)
	{
		this->mName = rhs.mName;
		this->mAge = rhs.mAge;
		this->mGender = rhs.mGender;
		this->mHeight = rhs.mHeight;
	}

	return (*this);
}

string Person::getName() const
{
	return mName;
}

int Person::getAge() const
{
	return mAge;
}

string Person::getGender() const
{
	return mGender;
}

int Person::getHeight() const
{
	return mHeight;
}

void Person::setName(const string & newName)
{
	mName = newName;
}

void Person::setAge(const int & newAge)
{
	mAge = newAge;
}

void Person::setGender(const string & newGender)
{
	mGender = newGender;
}

void Person::setHeight(const int & newHeight)
{
	mHeight = newHeight;
}

ostream & operator<<(ostream & output, const Person & person)
{
	output << "Name: " << person.getName() << endl;
	output << "Age:	" << person.getAge() << endl;
	output << "Gender: " << person.getGender() << endl;
	output << "Height: " << person.getHeight() << endl;

	return output;
}

fstream & operator>>(fstream & input, Person & person)
{
	char name[100];
	input.getline(name, 100);
	char age[100];
	input.getline(age, 100);
	char gender[100];
	input.getline(gender, 100);
	char height[100];
	input.getline(height, 100);

	int newAge = atoi(age);
	int newHeight = atoi(height);

	person.setName(name);
	person.setAge(newAge);
	person.setGender(gender);
	person.setHeight(newHeight);
}
