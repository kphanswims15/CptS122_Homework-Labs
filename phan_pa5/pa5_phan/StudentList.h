#pragma once
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "StudentNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;
using std::ostream;
using std::vector;

/*
Date Created: March 6, 2016
Description: This defines a containd for a List.
*/
class StudentList
{
public:
	//constructor
	StudentList();

	//copy constructor
	StudentList(const StudentList &copyList);

	//destructor
	~StudentList();

	//getter
	StudentNode * getHeadPtr() const;

	//setter
	void setHeadPtr(StudentNode * const pNewHead);

	bool insertAtFront(const int newRecordNumber, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel, const int newNumberOfDates, const vector<string> newAbsenceDates);
	bool isEmpty();
	void takeAttendance();
	void printListForReport1(ofstream output);

private:
	//point to start or head of the singly linked list
	StudentNode *mpHead;

	StudentNode *makeNode(const int newRecordNumber, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel);
	void destroyStudentListHelper(StudentNode * const pMem);
	void destroyStudentList();
};