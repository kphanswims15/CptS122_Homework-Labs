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

//Date Created: February 20, 2016
//Date Last Modified: February 22, 2016
//Description: This is used to represent an exercise plan. It include three data memebers.
//		goal steps which is an integer and represents the maximum steps. plan name and date 
//		which are both strings.
class ExercisePlan
{
public:
	//constructor 
	ExercisePlan(int newGoal_steps = 0, string newPlan_name = "", string newDate = "");

	//copy constructor 
	ExercisePlan(ExercisePlan & plan);

	//deconstructor
	~ExercisePlan();

	//setters
	void setGoal_steps(const int newGoal_steps);
	void setPlan_name(const string newPlan_name);
	void setDate(const string newDate);

	//getters
	int getGoal_steps() const;
	string getPlan_name() const;
	string getDate() const;

	ExercisePlan & editGoal(ExercisePlan & plan);
	void printExercisPlan(ExercisePlan & plan);

private:
	int goal_steps;
	string plan_name;
	string date;
};

//overloaded functions
ostream & operator<< (ostream &output, const ExercisePlan & plan);