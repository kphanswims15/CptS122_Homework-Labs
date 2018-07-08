#include "StudentNode.h"

/*
Date Created: March 5, 2016
Date Last Modified: March 28, 2015
Description: This is a constructor. It constructs a StudentNode and initializes the object.
*/
StudentNode::StudentNode(int newRecordNumber, int newID, string newName, string newEmail, string newUnits, string newProgram, string newLevel, int newNumberOfAbsences, vector<string> newAbsenceDates)
{
	mRecordNumber = newRecordNumber;
	mID = newID;
	mName = newName;
	mEmail = newEmail;
	mUnits = newUnits;
	mProgram = newProgram; 
	mLevel = newLevel;
	mNumberOfAbsences = newNumberOfAbsences;
	mAbsenceDates = newAbsenceDates;
	
	mpNext = nullptr;
}

/*
Date Created: March 5, 2016
Description: This is a copy constructor. It is implicitly invoked copying a ListNode object during
construction of another ListNode object, or when a ListNode object is passed-by-value.
*/
StudentNode::StudentNode(const StudentNode & copy)
{
	mRecordNumber = copy.mRecordNumber;
	mID = copy.mID;
	mName = copy.mName;
	mEmail = copy.mEmail;
	mUnits = copy.mUnits;
	mProgram = copy.mProgram;
	mLevel = copy.mLevel;
	mNumberOfAbsences = copy.mNumberOfAbsences;
	mAbsenceDates = copy.mAbsenceDates;

	mpNext = copy.mpNext;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retrieve a copy of the RecordNumber
in the Node.
*/
int StudentNode::getRecordNumber() const
{
	return mRecordNumber;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retrieve a copy of the ID in the
Node.
*/
int StudentNode::getID() const
{
	return mID;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retrieve a copy of the Name
in the Node.
*/
string StudentNode::getName() const
{
	return mName;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retrieve a copy of the Email
in the Node.
*/
string StudentNode::getEmail() const
{
	return mEmail;
}

/*
Date Created: March 6, 2016
Description: This is a getterr and it is used to retrieve a copy of the Units
in the Node.
*/
string StudentNode::getUnits() const
{
	return mUnits;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retreive a copy of the Program
in the Node.
*/
string StudentNode::getProgram() const
{
	return mProgram;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retrieve a copy of the Level
		in the Node.
*/
string StudentNode::getLevel() const
{
	return mLevel;
}

/*
Date Created: March 28, 2016
Description: This is a getter and it is used to retrieve a copy of the NumberOfAbsences
		in the Node.
*/
int StudentNode::getNumberOfAbsences() const
{
	return mNumberOfAbsences;
}

/*
Date Created: March 28, 2016
Description: This is a getter and it is used to retrieve a copy of the AbscenceDates
		in the Node.
*/
vector<string> StudentNode::getAbsenceDates() const
{
	return mAbsenceDates;
}

/*
Date Created: March 6, 2016
Description: This is a getter and it is used to retrieve a copy of the NextPtr
in the Node.
*/
StudentNode * StudentNode::getNextPtr() const
{
	return mpNext;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the RecordNumber in the
Node.
*/
void StudentNode::setRecordNumber(const int newRecordNumber)
{
	mRecordNumber = newRecordNumber;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the ID in the Node.
*/
void StudentNode::setID(const int newID)
{
	mID = newID;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the Name in the Node.
*/
void StudentNode::setName(const string newName)
{
	mName = newName;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the Email in the Node.
*/
void StudentNode::setEmail(const string newEmail)
{
	mEmail = newEmail;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the Units in the Node.
*/
void StudentNode::setUnits(const string newUnits)
{
	mUnits = newUnits;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the program in the Node.
*/
void StudentNode::setProgram(const string newProgram)
{
	mProgram = newProgram;
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the level in the Node.
*/
void StudentNode::setLevel(const string newLevel)
{
	mLevel = newLevel;
}

/*
Date Created: March 28, 2016
Description: This is a setter and it is used to modifiy the numberOfAbsences in the Node.
*/
void StudentNode::setNumberOfAbsences(const int newNumberOfAbsences)
{
	mNumberOfAbsences = newNumberOfAbsences;
}

/*
Date Created: March 28, 2016
Description: This is a setter and it is used to modify the AbsenceDates in the Node.
*/
void StudentNode::setAbsenceDates(const vector<string> newDates)
{
	mAbsenceDates = newDates;
}

/*
Date Created: March 28, 2016
Description: This is a setter and it changes using the index or add a newDate
*/
void StudentNode::setAbsenceDates(const string newAbsentDates, int index)
{
	if (index < 0)
	{
		mAbsenceDates.push_back(newAbsentDates);
	}
	else
	{
		mAbsenceDates.push_back(newAbsentDates);
	}
}

/*
Date Created: March 6, 2016
Description: This is a setter and it is used to modify the nextPtr in the Node.
*/
void StudentNode::setNextPtr(StudentNode * const pNewNext)
{
	mpNext = pNewNext;
}

////////// non-member functions //////////

/*
Date Created: March 29, 2016
Description: This is used to print to the master file.
*/
ofstream & operator<<(ofstream & output, StudentNode & student)
{
	output << "Record Number: " << student.getRecordNumber() << endl;
	output << "ID: " << student.getID() << endl;
	output << "Name: " << student.getName() << endl;
	output << "Email: " << student.getEmail() << endl;
	output << "Units: " << student.getUnits() << endl;
	output << "Program:	" << student.getProgram() << endl;
	output << "Level: " << student.getLevel() << endl;
	output << "Number of absences: " << student.getNumberOfAbsences() << endl;
	output << "Dates: " << endl;

	if (!student.getAbsenceDates().empty())
	{
		for (string date : student.getAbsenceDates())
		{
			output << date << "\n";
		}
	}

	return output;
}