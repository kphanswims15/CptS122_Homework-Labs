#pragma once

#include <iostream>
#include <fstream> 
#include <string>

#include "DietClass.h"
#include "ExerciseClass.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

//Date Created: February 22, 2016
//Description: This contains two lists of weekly (7 day) plans: one diet and one exercise
//		weekly plan. It also contain two fstream objects (input/output file streams): one
//		for each file.
class FitnessAppWrapper
{
public:
	
	FitnessAppWrapper(DietPlan new_mDp[7] = { 0 }, ExercisePlan new_mEp[7] = { 0 });
	~FitnessAppWrapper();
	static void runApp(void);
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyplan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyplan[]);
	void displayDailyPlan(DietPlan &plan);
	void displayDailyPlan(ExercisePlan &plan);
	void displayWeeklyPlan(DietPlan weeklyplan[]);
	void displayWeeklyPlan(ExercisePlan weeklyplan[]);
	void storeDailyPlan(ofstream & output, DietPlan & plan);
	void storeDailyPlan(ofstream & output, ExercisePlan & plan);
	void storeWeeklyPlan(ofstream & output, DietPlan weeklyplan[]);
	void storeWeeklyPlan(ofstream & output, ExercisePlan weeklyplan[]);
	void edit(DietPlan weeklyplan[]);
	void edit(ExercisePlan weeklyplan[]);
	void displayMenu();

private:
	DietPlan mDp[7];
	ExercisePlan mEp[7];
};

fstream & operator>> (fstream & input, DietPlan & plan);
fstream & operator>> (fstream &input, ExercisePlan & plan);
ofstream & operator<< (ofstream & output, DietPlan & plan);
ofstream & operator<< (ofstream & output, ExercisePlan & plan);