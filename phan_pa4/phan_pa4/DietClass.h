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
//Description: This is used to represent a daily diet plan. It includes three data members
//		goal calories an integer which represents the maximum intake. plan name and date which 
//		are both strings.
class DietPlan
{
public:
	//constructor
	DietPlan(int newGoal_calories = 0, string newPlan_name = "", string newDate = "");

	//copy constructor
	DietPlan(DietPlan & plan);

	//deconstructor
	~DietPlan();

	//setters
	void setGoal_calories(const int newGoal_calories);
	void setPlan_name(const string newPlan_name);
	void setDate(const string newDate);

	//getters
	int getGoal_calories() const;
	string getPlan_name() const;
	string getDate() const;

	DietPlan & editGoal(DietPlan & newPlan);
	void printDietPlan(DietPlan & plan);

private:
	int goal_calories;
	string plan_name;
	string date;
};

//overloaded functions
ostream & operator<< (ostream &output,  const DietPlan & plan);