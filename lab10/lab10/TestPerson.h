#pragma once

#include <iostream>
#include <fstream> 
#include <string>

#include "person.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

class TestPerson : public Person
{
public:
	TestPerson(const string &newName = "", const int &newAge = 0, const string &newGender = "", const int &newHeight = 0);

private:
	string mName;
	int mAge;
	string mGender;
	int mHeight;
};