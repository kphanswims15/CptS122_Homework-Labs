#include "ExcercisePlan.h"

////////// Member functions //////////

ExcercisePlan::ExcercisePlan(const string & newPlanName, const string & newDate, const int & newGoalStep)
{
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalSteps = newGoalStep;
	cout << "Inside ExercisePlan's constructor!" << endl;
}

ExcercisePlan::ExcercisePlan(const ExcercisePlan & copy)
{
	this->mPlanName = copy.mPlanName; // this is a copy a std::string to another one, overloaded assignment for one is called here
	this->mDate = copy.mDate; // calls std::string overloaded assignment operator
	this->mGoalSteps = copy.mGoalSteps; // simple assignment between integers
}

ExcercisePlan::~ExcercisePlan()
{
	// the ExcercisePlan object will be stored in an array in the fitnessAppWrapper class
	cout << "Inside of ExcercisePlan's destructor!" << endl;
}

ExcercisePlan & ExcercisePlan::operator=(const ExcercisePlan & rhs)
{
	// check for self assignment
	if (this != &rhs)
	{
		// no self assignment in here
		this->mPlanName = rhs.mPlanName; // this is copy a std::string to another one; std::string is an object, so the overloaded 
										// assignment (=) for one is called here!
		this->mDate = rhs.mDate; // calls std::string overloaded assignment (=) operator!
		this->mGoalSteps = rhs.mGoalSteps; // simpler assignment between integers
	}

	return (*this);
}

//getters - allow us to return a copy of the private data members to outside the object
string ExcercisePlan::getPlanName() const // const member function - should not modify data in object 
{
	return this->mPlanName;
}

string ExcercisePlan::getDate() const
{
	return this->mDate;
}

int ExcercisePlan::getGoalSteps() const
{
	return this->mGoalSteps;
}

// setters - allows us to modify the private data members with values from outside the object
void ExcercisePlan::setPlanName(const string & newPlanName)
{
	this->mPlanName = newPlanName; // calls std::string overloaded assignment (=) operator
}

void ExcercisePlan::setDate(const string & newDate)
{
	this->mDate = newDate; // calls std::string overloaded assignment (=) operator
}

void ExcercisePlan::setGoalSteps(const int & newGoalSteps)
{
	this->mGoalSteps = newGoalSteps;
}

void ExcercisePlan::editGoal() // prompt the user for a different goal - display plan with changes to screen
{
	cout << "Please enter a new step goal: ";
	cin >> this->mGoalSteps;

	cout << (*this) << endl; // can use "*this" here because we've overloaded the stream insertion << (ostream, ExercisePlan)
							 // and we want to see the current object's plan details.
}

////////// nonmember functions //////////

// format: Plan name
//		   Goal Step
//		   Date

ostream & operator<<(ostream & lhs, const ExcercisePlan & rhs)
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions cout << ExcerisePlan object1 << ExcercisePlan object2...
}

// format: Plan name
//		   Goal Step
//		   Date

fstream & operator<<(fstream & lhs, const ExcercisePlan & rhs)
{
	// cast lhs to ofstream so can easily output std::string (plan name)
	((ofstream &)(lhs)) << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs; // allows for chaining of stream insertions cout << ExcercisePlan object1 << Excercise object2...
}

// format: Plan name
//		   Goal Step
//		   Date

fstream & operator>>(fstream & lhs, ExcercisePlan & rhs)
{
	char tempString[100] = "";
	lhs.getline(tempString, 100); // read the plan name including the newline in the file
	rhs.setPlanName(tempString); // when the char * is passed into setPlanName a std::string is constructed and 
								 // initialized with the char * value
	int goalStep = 0;
	lhs.getline(tempString, 100); // read the goal calories line as a string then, convert to an integer, so we can read in the newline
	goalStep = atoi(tempString); // changes to an int so it can match the same type
	rhs.setGoalSteps(goalStep); 
	lhs.getline(tempString, 100); // read the date from the file, also reads newline
	rhs.setDate(tempString);

	return lhs; // allows for chaining of stream extractions fstr >> Excercise object1 >> ExcercisePlan object2...
}
