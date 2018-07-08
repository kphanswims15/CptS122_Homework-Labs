#include "FitnessAppWrapper.h"

//Date Created: February 24, 2016
//Description: This is a constructor for  the FintenssAppWrapper.
FitnessAppWrapper::FitnessAppWrapper(DietPlan new_mDp[7], ExercisePlan new_mEp[7])
{
	
}

//Date Created: February 24, 2016
//Description: Does nothing, but it is invoked when an object goes out of scope. 
FitnessAppWrapper::~FitnessAppWrapper()
{

}

//Date Created: February 24, 2016
//Date Last Modified: February 29, 2016
//Description: Starts the main application
void FitnessAppWrapper::runApp(void)
{
	int option = 0;
	FitnessAppWrapper app;
	fstream Diet, Exercise;
	ofstream DietO, ExerciseO;

	do
	{
		app.displayMenu();

		cout << "Please enter an option: ";
		cin >> option;
		system("cls");

		switch (option)
		{
		case 1: //load weekly diet plan from the file
			Diet.open("DietClass.txt");
			app.loadWeeklyPlan(Diet, app.mDp);
			cout << "Your plans have been loaded." << endl;
			Diet.close();
			system("pause");
			system("cls");
			break;
		case 2: //load weekly excercise plan from the file
			Exercise.open("ExerciseClass.txt");
			app.loadWeeklyPlan(Exercise, app.mEp);
			cout << "Your plans have been loaded." << endl;
			Exercise.close();
			system("pause");
			system("cls");
			break;
		case 3: //store weekly diet plan to file
			DietO.open("DietClass.txt");
			app.storeWeeklyPlan(DietO, app.mDp);
			cout << "Your plans have been stored." << endl;
			DietO.close();
			system("pause");
			system("cls");
			break;
		case 4: //store weekly exercise plan from the file
			ExerciseO.open("ExerciseClass.txt");
			app.storeWeeklyPlan(ExerciseO, app.mEp);
			cout << "Your plans have been stored." << endl;
			ExerciseO.close();
			system("pause");
			system("cls");
			break;
		case 5: //display weekly diet plan to the screen
			app.displayWeeklyPlan(app.mDp);
			system("pause");
			system("cls");
			break;
		case 6: //display weekly exercise plan to the screen
			app.displayWeeklyPlan(app.mEp);
			system("pause");
			system("cls");
			break;
		case 7: //edit daily diet plan
			app.edit(app.mDp);
			system("pause");
			system("cls");
			break;
		case 8: //edit daily exercise plan
			app.edit(app.mEp);
			system("pause");
			system("cls");
			break;
		case 9: //exit
				//uploads the latest changes to the file
			cout << "Thank you for using the Fitness App." << endl;
			DietO.open("Diet.txt");
			ExerciseO.open("Exercise.txt");
			app.storeWeeklyPlan(DietO, app.mDp);
			app.storeWeeklyPlan(ExerciseO, app.mEp);
			DietO.close();
			ExerciseO.close();
			system("pause");
			system("cls");
			break;
		default:
			cout << "Invalid input." << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (option != 9);
}

//Date Created: February 24, 2016
//Description: Reads one record from the given stream.
void FitnessAppWrapper::loadDailyPlan(fstream & fileStream, DietPlan & plan)
{
	fileStream >> plan;
}

//Date Created: February 24, 2016
//Description: Reads on record from the given stream
void FitnessAppWrapper::loadDailyPlan(fstream & fileStream, ExercisePlan & plan)
{
	fileStream >> plan;
}

//Date Created: February 24, 2016
//Description: Reads all seven daily plans from the given stream
//Precondition: There must be 7 plans in the file.
void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, DietPlan weeklyplan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyplan[i]);
	}
}

//Date Created: February 24, 2016
//Description: Reads all seven daily plans from the given stream
//Precondtion: There must be 7 plans in the file.
void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, ExercisePlan weeklyplan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyplan[i]);
	}
}

//Date Created: February 24, 2016
//Description: Writes a daily plan to the screen
void FitnessAppWrapper::displayDailyPlan(DietPlan & plan)
{
	cout << plan;
}

//Date Created: February 24, 2016
//Description: Writes a daily plan to the screen
void FitnessAppWrapper::displayDailyPlan(ExercisePlan & plan)
{
	cout << plan;
}

//Date Created: February 24, 2016
//Description: Writes a weekly plan to the screen.
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyplan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyplan[i]);
	}

}

//Date Created: February 24, 2016
//Description: Writes a weekly plan to the screen.
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyplan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyplan[i]);
	}
}

//Date Created: February 24, 2016
//Description: Writes a daily plan to a file. Overwrites the file entirely.
void FitnessAppWrapper::storeDailyPlan(ofstream & output, DietPlan & plan)
{
	output << plan;
}

//Date Created: February 24, 2016
//Description: Writes a daily plan to a file. Overwrites the file entirely.
void FitnessAppWrapper::storeDailyPlan(ofstream & output, ExercisePlan & plan)
{
	output << plan;
}

//Date Created: February 24, 2016
//Description: Writes a weekly plan to a file. 
void FitnessAppWrapper::storeWeeklyPlan(ofstream & output, DietPlan weeklyplan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		storeDailyPlan(output, weeklyplan[i]);
	}
}

//Date Created: February 24, 2016
//Description: Writes a weekly plan to a file. 
void FitnessAppWrapper::storeWeeklyPlan(ofstream & output, ExercisePlan weeklyplan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		storeDailyPlan(output, weeklyplan[i]);
	}
}

//Date Created: February 29, 2016
//Description: Edits a plan in the DietPlan
void FitnessAppWrapper::edit(DietPlan weeklyplan[])
{
	char planName[100];
	int i = 0;

	cout << "Please enter the plan name you want to edit." << endl;
	cin.ignore();
	cin.getline(planName, 100);

	while (planName != weeklyplan[i].getPlan_name() && i < 7)
	{
		i++;
	}

	if (i != 7)
	{
		weeklyplan[i].editGoal(weeklyplan[i]);
		weeklyplan[i].printDietPlan(weeklyplan[i]);
	}
	else
	{
		cout << "There are no plans by that name." << endl;
	}
}

//Date Created: February 29, 2016
//Description: Edits a plan in the ExericsePlan
void FitnessAppWrapper::edit(ExercisePlan weeklyplan[])
{
	char planName[100];
	int i = 0;

	cout << "Please enter the plan name you want to edit." << endl;
	cin.ignore();
	cin.getline(planName, 100);

	while (planName != weeklyplan[i].getPlan_name() && i < 7)
	{
		i++;
	}

	if (i != 7)
	{
		weeklyplan[i].editGoal(weeklyplan[i]);
		weeklyplan[i].printExercisPlan(weeklyplan[i]);
	}
	else
	{
		cout << "There are no plans by that name." << endl;
	}
}

//Date Created: February 24, 2016
//Description: Displays nine menu options.
void FitnessAppWrapper::displayMenu()
{
	cout << "Welcome to the Fitness App" << endl;
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from the file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit exercise plan." << endl;
	cout << "9. Exit." << endl;
}

//Date Created: February 24, 2016
//Description: Provides a different/overload version of >>. It is defined
//		parts in function based on atomic operations
fstream & operator>>(fstream & input, DietPlan & plan)
{
	char plan_name[100];
	int goal_calorie = 0;
	char date[100];
	char newLine[100];
	char blank[100];

	input.getline(plan_name, 100);
	input >> goal_calorie;
	input.getline(newLine, 100);
	input.getline(date, 100);
	input.getline(blank, 100);
	
	plan.setPlan_name(plan_name);
	plan.setGoal_calories(goal_calorie);
	plan.setDate(date);

	return input;
}

//Date Created: February 24, 2016
//Date Last Modified: February 25, 2016
//Description: Provides a different/overload version of >>. It is defined
//		parts in function based on atomic operations
fstream & operator>>(fstream & input, ExercisePlan & plan)
{
	char plan_name[100];
	int goal_step = 0;
	char date[100];
	char newLine[100];
	char blank[100];

	input.getline(plan_name, 100);
	input >> goal_step;
	input.getline(newLine, 100);
	input.getline(date, 100);
	input.getline(blank, 100);

	plan.setPlan_name(plan_name);
	plan.setGoal_steps(goal_step);
	plan.setDate(date);

	return input;
}

//Date Created: February 29, 2016
//Description: Overloads this << operator so it can load the whole plan to the file.
ofstream & operator<<(ofstream & output, DietPlan & plan)
{
	output << plan.getPlan_name() << endl;
	output << plan.getGoal_calories() << endl;
	output << plan.getDate() << endl << endl;

	return output;
}

//Date Created: February 29, 2016
//Description: Overloads this << operator so it can load the whole plan to the file.
ofstream & operator<<(ofstream & output, ExercisePlan & plan)
{
	output << plan.getPlan_name() << endl;
	output << plan.getGoal_steps() << endl;
	output << plan.getDate() << endl;

	return output;
}
