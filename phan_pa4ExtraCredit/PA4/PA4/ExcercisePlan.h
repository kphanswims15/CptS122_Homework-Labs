/*
File: ExcercisePlan.h
author: Kimi Phan
Date: March 30, 2016
Brief: This is the other part of the fitness app and this deals with the exercise plan.

Revision history:

*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExcercisePlan
{
public:
	// constructor with default arguments - when a ExercisePlan is constructed or instantiated
	// it supplies values for each of the member variables or leave them as the default ones
	ExcercisePlan(const string & newPlanName = "", const string & newDate = "", const int & newGoalStep = 0);

	// copy constructor - invoked during the construction of an object, when the object is set
	// to another object of same type; invoked when passing-by-value (making a copy)
	ExcercisePlan(const ExcercisePlan & copy);

	// destructor - invoked when an object leaves scope or is destroyed - if the object was created
	// on the heap aka dynamic, then call to delete the object (using delete operator) will simply 
	// invoke the constructor
	~ExcercisePlan();

	// overloaded assigment - always a member function
	ExcercisePlan & operator= (const ExcercisePlan & rhs);

	//getters - returns a copy of the private data members to outside the object
	string getPlanName() const; // const member function - should not modify data in object
	string getDate() const;
	int getGoalSteps() const;

	// setters - allows us to modify the private data members with values from outside the object.
	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalSteps(const int &newGoalSteps);

	void editGoal(); // prompts the user for a different goal - display plan with changes to the screen.

private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

// nonmember functions
ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs); // will allow cout << Excerise object1 << Excerise object2...
// write a complete ExcercisePlan to a file
fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs);
// read a complete ExcercisePlan from a file
fstream & operator>> (fstream &lhs, ExcercisePlan &rhs);