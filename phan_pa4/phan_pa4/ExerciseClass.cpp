#include "ExerciseClass.h"

//Date Created: February 22, 2016
//Description: This is the constructor of the ExercisePlan Class
ExercisePlan :: ExercisePlan(int newGoal_steps, string newPlan_name, string newDate)
{
	goal_steps = newGoal_steps;
	plan_name = newPlan_name;
	date = newDate;
}

//Date Created: February 22, 2016
//Date Last Modified: February 24, 2016
//Description: This is the copy constructor. It is implicitly invoked when passing a
//		EcxercisePlan object by value.
ExercisePlan::ExercisePlan(ExercisePlan & plan)
{
	goal_steps = plan.goal_steps;
	plan_name = plan.plan_name;
	date = plan.date;
}

//Date Created: February 24, 2016
//Description: Does nothing, but it is invoked when an object goes out of scope.
ExercisePlan::~ExercisePlan()
{

}

//Date Created: February 24, 2016
//Description: This is a setter that will modify the privated data member in the
//		object.
void ExercisePlan::setGoal_steps(const int newGoal_steps)
{
	goal_steps = newGoal_steps;
}

//Date Created: February 24, 2016
//Description: This is a setter tht will modify the private data member in the 
//		object.
void ExercisePlan::setPlan_name(const string newPlan_name)
{
	plan_name = newPlan_name;
}

//Date Created: February 24, 2016
//Description: This is a setter that will modify the private data member in the
//		object.
void ExercisePlan::setDate(const string newDate)
{
	date = newDate;
}

//Date Created: February 24, 2016
//Description: This is a getter that will get access to a copy of the private data members
//		in the object.
int ExercisePlan::getGoal_steps() const
{
	return goal_steps;
}

//Date Created: February 24, 2016
//Description: This is a getter that will get access to a copy of the private data members
//		in the object.
string ExercisePlan::getPlan_name() const
{
	return plan_name;
}

//Date Created: February 24, 2016
//Description: This is a getter that will get access to a copy of the private data members
//		in the object
string ExercisePlan::getDate() const
{
	return date;
}

//Date Created: February 24, 2016
//Description: Promts the user for a plan name and a new goal and uses the values to change
//		the goal in the plan.
ExercisePlan & ExercisePlan::editGoal(ExercisePlan & newPlan)
{
	int newStep_goal;

	cout << "New step goal: ";
	cin >> newStep_goal;

	setGoal_steps(newStep_goal);
	
	return newPlan;
}

//Date Created: February 24, 2016
//Description: Prints out the ExercisePlan that was changed.
void ExercisePlan::printExercisPlan(ExercisePlan & plan)
{
	cout << plan;
}

//Date Created: February 24, 2016
//Description: Provides a different/overloaded version of << defines parts in function
//		based on a atomic operations.
ostream & operator<<(ostream & output, const ExercisePlan & plan)
{
	output << "Plan Name: " << plan.getPlan_name() << endl;
	output << "Step Goal: " << plan.getGoal_steps() << endl;
	output << "Date: " << plan.getDate() << endl << endl;

	return output;
}
