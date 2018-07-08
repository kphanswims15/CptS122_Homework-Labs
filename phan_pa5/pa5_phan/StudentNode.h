#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector; 

/*
Date Created: March 4, 2016
Date Last Modified: March 28, 2016
Description: Holds information about each of the nodes and it creates nodes so it can
		be inserted into the list.
*/
class StudentNode
{
public:
	//constructor
	StudentNode(int newRecordNumber = 0, int newID = 0, string newName = "", string newEmail = "", string newUnits = "", string newProgram = "", string newLevel = "", int newNumberOfAbsences = 0, vector<string> newAbsenceDates = {0});

	//copy constructor
	StudentNode(const StudentNode & copy);

	//getters
	int getRecordNumber() const;
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	int getNumberOfAbsences() const;
	vector<string> getAbsenceDates() const;
	StudentNode * getNextPtr() const;

	//setters
	void setRecordNumber(const int newRecordNumber);
	void setID(const int newID);
	void setName(const string newName);
	void setEmail(const string newEmail);
	void setUnits(const string newUnits);
	void setProgram(const string newProgram);
	void setLevel(const string newLevel);
	void setNumberOfAbsences(const int newNumberOfAbsences);
	void setAbsenceDates(const vector<string> newDates);
	void setAbsenceDates(const string newAbsentDates, int index);
	void setNextPtr(StudentNode * const pNewNext);

private:
	int mRecordNumber;
	int mID;
	string mName;
	string mEmail;
	string mUnits;
	string mProgram;
	string mLevel;
	int mNumberOfAbsences;
	vector<string> mAbsenceDates;

	StudentNode *mpNext;
};

ofstream & operator<< (ofstream & output, StudentNode & student);