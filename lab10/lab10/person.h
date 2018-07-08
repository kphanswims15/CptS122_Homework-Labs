#pragma once

#include <iostream>
#include <fstream> 
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

class Person
{
public:
	// constructor
	Person(string newName = "", int newAge = 0, string newGender = "", int newHeight = 0);

	// copy constructor
	Person(const Person & copy);

	// destructor
	~Person();

	// overloaded assignment 
	Person & operator= (const Person &rhs);

	// getters
	string getName() const;
	int getAge() const;
	string getGender() const;
	int getHeight() const;

	// setters 
	void setName(const string &newName);
	void setAge(const int &newAge);
	void setGender(const string &newGender);
	void setHeight(const int &newHeight);

private:
	string mName;
	int mAge;
	string mGender;
	int mHeight;
};

////////// non-member functions //////////
ostream & operator<< (ostream & output, const Person & person);
fstream & operator>> (fstream & input, Person & person);