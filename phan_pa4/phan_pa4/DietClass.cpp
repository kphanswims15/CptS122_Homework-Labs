#include "DietClass.h"

//Date Created: February 22, 2016
//Description: This is the constructor for the DietPlan class
DietPlan::DietPlan(int newGoal_calories, string newPlan_name, string newDate)
{
	goal_calories = newGoal_calories;
	plan_name = newPlan_name;
	date = newDate;
}

//Date Created: February 22, 2016
//Description: This is the copy constructer which implicitly invoked when passing 
//		a DietPlan object by value. 
DietPlan::DietPlan(DietPlan & plan)
{
	goal_calories = plan.goal_calories;
	plan_name = plan.plan_name;
	date = plan.date;
}

//Date Created: February 22, 2016
//Description: Does nothing, but invokes when an object goes out of scope.
DietPlan:: ~DietPlan()
{

}

//Date Created: February 22, 2016
//Description: This is a setter that will modify the private data member in the 
//		object.
void DietPlan::setGoal_calories(const int newGoal_calories)
{
	goal_calories = newGoal_calories;
}

//Date Created: February 22, 2016
//Description: This is a setter that will modify the private data member in the
//		object.
void DietPlan::setPlan_name(const string newPlan_name)
{
	plan_name = newPlan_name;
}

//Date Created: February 22, 2016
//Description: This is a setter that will modify the private data member in the 
//		object.
void DietPlan::setDate(const string newDate)
{
	date = newDate;
}

//Date Created: February 22, 2016
//Description: This is a getter that will get access to a copy of the private data members
//		in objects.
int DietPlan::getGoal_calories() const
{
	return goal_calories;
}

//Date Created: February 22, 2016
//Description: This is a getter that will get access to a copy of the private data members
//		in objects.
string DietPlan::getPlan_name() const
{
	return plan_name;
}

//Date Created: February 22, 2016
//Description: This is a getter that will get access to a copy of the private data members
//		in objects.
string DietPlan::getDate() const
{
	return date;
}

//Date Created: February 22, 2016
//Description: Prompts the user for a plan name and a new goal and uses the values to change
//		the goal in the plan.
DietPlan & DietPlan::editGoal(DietPlan & newPlan)
{
	int newCalorie_goal;

	cout << "New calorie goal: ";
	cin >> newCalorie_goal;

	setGoal_calories(newCalorie_goal);

	return newPlan;
}

//Date Created: February 22, 2016
//Description: Prints out the DietPlan that was changed.
void DietPlan::printDietPlan(DietPlan & plan)
{
	cout << plan;
}

//Date Created: February 22, 2016
//Description: Provides a different/overloaded version of << defines parts in function
//		based on atomic operations
ostream & operator<< (ostream &output, const DietPlan & plan)
{
	output << "Plan Name: " << plan.getPlan_name() << endl;
	output << "Calorie Goal: " << plan.getGoal_calories() << endl;
	output << "Date: " << plan.getDate() << endl << endl;

	return output;
}
