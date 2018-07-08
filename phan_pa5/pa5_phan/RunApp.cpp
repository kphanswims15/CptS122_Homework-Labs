#include "RunApp.h"

/*
Date Created: March 28, 2016 
Description: This runs the whole app
*/
void RunApp::runApp()
{
	ifstream csv, masterRead;
	ofstream master, report1, report2, report3;
	int option;
	
	do
	{
		displayMenu();
		cin >> option;
		system("cls");

		switch (option)
		{
		case 1: // reads the .csv course file and overwrites the master list
			csv.open("classList.csv");
			master.open("MasterList.txt");

			loadStudents(csv, mList);
			outputStudents(master, mList);

			system("pause");
			system("cls");

			csv.close();
			master.close();
			break;
		case 2: // Populates the mast list with previous nodes from the master.txt
			masterRead.open("MasterList.txt");

			readFromMasterList(masterRead, mList);

			system("pause");
			system("cls");

			masterRead.close();
			break;
		case 3: // Stores contents of the master list's nodes to master.txt
			master.open("MasterList.txt");

			printToMasterList(master, mList);

			system("pause");
			system("cls");

			master.close();
			break;
		case 4: // Runs through the master list, displays each student's name, and prompts if he/she was absent for the current day
			markAbsences(mList);

			system("pause");
			system("cls");
			
			break;
		case 5: // generates reports 
			report1.open("report1.txt");
			report2.open("report2.txt");
			report3.open("report3.txt");

			reportWrapper(report1, report2, report3, mList);

			system("pause");
			system("cls");

			report1.close();
			report2.close();
			report2.close();

			break;
		case 6: // exit
			cout << "Thanks for using the attendance tracker." << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "Invalid input" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (option != 6);
}

/*
Date Created: March 28, 2016
Description: This loads the strudents from the csv file.
*/
void RunApp::loadStudents(ifstream & fileStream, StudentList & students)
{
	if (fileStream.is_open())
	{
		fileStream >> students;

		cout << "Your file was loaded." << endl;
	}
	else
	{
		cout << "Your file was not loaded." << endl;
	}
}

/*
Date Created: March 28, 2016
Description: This outputs the information from the csv file to the master file.
*/
void RunApp::outputStudents(ofstream & fileStream, StudentList & students)
{
	fileStream << students;
}

/*
Date Created: March 28, 2016
Description: This reads from the master list.
*/
void RunApp::readFromMasterList(ifstream & fileStream, StudentList & students)
{
	if (fileStream.is_open())
	{
		while (!fileStream.eof())
		{
			int recordNumber;
			fileStream >> recordNumber;
			int id;
			fileStream >> id;
			string firstName;
			fileStream >> firstName;
			string lastName;
			fileStream >> lastName;
			string name = firstName + " " + lastName;
			string email;
			fileStream >> email;
			string units;
			fileStream >> units;
			string program;
			fileStream >> program;
			string level;
			fileStream >> level;
			int numberOfAbsences;
			fileStream >> numberOfAbsences;

			string date;
			vector<string> absenceDates;

			while (date != "End")
			{
				fileStream >> date;

				if (date != "End")
				{
					absenceDates.push_back(date);
				}
			}

			students.insertAtFront(recordNumber, id, name, email, units, program, level, numberOfAbsences, absenceDates);
		}

		cout << "Your file was loaded." << endl;
	}
	else
	{
		cout << "Your file was not loaded." << endl;
	}
}

/*
Date Created: March 28, 2016
Description: Prints out into to the master file.
*/
void RunApp::printToMasterList(ofstream & fileStream, StudentList & students)
{
	if (fileStream.is_open())
	{
		fileStream << students;

		cout << "Your file was uploaded." << endl;
	}
	else
	{
		cout << "Your file was not uploaded." << endl;
	}
}

/*
Date Created: March 28, 2016
Description: This marks if the student was absent or not
*/
void RunApp::markAbsences(StudentList & student)
{
	student.takeAttendance();
}

/*
Date Created: March 29, 2016
Description: This is used to put the generate functions together
*/
void RunApp::reportWrapper(ofstream  & report1, ofstream  & report2, ofstream & report3, StudentList & students)
{
	int option = 0;

	do
	{
		displaySubMenu();
		cin >> option;
		system("cls");

		switch (option)
		{
		case 1: // for all students
			generateReportsForAllStudents(report1, students);
			break;
		case 2: // generates reports based off of a number inputed by the user
			cout << "Enter number of absences: ";
			int num;
			cin >> num;
			system("cls");
			generateReportsForStudentsThatMatchOrExceed(report2, students, num);
			break;
		case 3: // generate date reports
			cout << "Enter date (mm-dd-yyyy): ";
			string date;
			cin >> date;
			system("cls");
			generateDateReport(report3, students, date);
			break;
		}
	} while (option < 1 && option > 3);
}

/*
Date Created: March 28, 2016
Decription: This generates reports for all students
*/
void RunApp::generateReportsForAllStudents(ofstream & outFileStream, StudentList & students)
{
	if (outFileStream.is_open())
	{
		StudentNode * pCur = students.getHeadPtr();
		
		while (pCur != nullptr)
		{
			outFileStream << "Name: " << pCur->getName() << endl;
			outFileStream << "Number of absences: " << pCur->getNumberOfAbsences() << endl;
			
			vector<string> absences = pCur->getAbsenceDates();
			for (string absence : absences)
			{
				outFileStream << "Date: " << absence << endl;
			}

			if (pCur->getNextPtr() != nullptr)
			{
				outFileStream << endl;
			}

			pCur = pCur->getNextPtr();
		}

		cout << "Your report was generated." << endl;
	}
	else
	{
		cout << "Your report was not generated." << endl;
	}
}

/*
Date Created: March 29, 2016
Description: This generates a report for all students that exceed a number of absences a user inputs.
*/
void RunApp::generateReportsForStudentsThatMatchOrExceed(ofstream & fileStream, StudentList & students, int numberOfAbsences)
{
	if (fileStream.is_open())
	{
		StudentNode * pCur = students.getHeadPtr();

		while (pCur != nullptr)
		{
			if (pCur->getNumberOfAbsences() >= numberOfAbsences)
			{
				fileStream << "Name: " << pCur->getName() << endl;
			}

			pCur = pCur->getNextPtr();
		}

		cout << "Your report was generated." << endl;
	}
	else
	{
		cout << "Your report was not generated." << endl;
	}
}

/*
Date Created: March 29, 2016
Description: This generates a report for the students that were gone on this date.
*/
void RunApp::generateDateReport(ofstream & fileStream, StudentList & students, string date)
{
	if (fileStream.is_open())
	{
		StudentNode * pCur = students.getHeadPtr();

		while (pCur != nullptr)
		{
			vector<string> absences = pCur->getAbsenceDates();
			for (string absence : absences)
			{
				if (absence == date)
				{
					fileStream << pCur->getName() << endl;
				}
			}
			pCur = pCur->getNextPtr();
		}

		cout << "Your report was generated." << endl;
	}
	else
	{
		cout << "Your report was not generated." << endl;
	}
}

/*
Date Created: March 28, 2016
Description: This prints out a sub menu to generate reports.
*/
void RunApp::displaySubMenu()
{
	cout << "1. Generate report for all students." << endl;
	cout << "2. Generate report for students with absences that match or exceed." << endl;
	cout << "3. Generate date report." << endl;
	cout << "4. Exit" << endl << endl;

	cout << "Choose an option: ";
}

/*
Date Created: March 28, 2016
Description: This displays the whole menu for the app.
*/
void RunApp::displayMenu()
{
	cout << "Welcome to the Attendance Tracker!!!" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Generate report" << endl;
	cout << "6. Exit" << endl << endl;

	cout << "Please choose an option: ";
}

////////// non-member functions //////////

/*
Date Created: March 9, 2016
Description: This overloaded operator >> will read each line of the input .csv file and extract the information
Precondition: The file must be open
*/
ifstream & operator>> (ifstream &input, StudentList &rhs)
{
	char line[100] = "";
	input.getline(line, 100);

	while (!input.eof())
	{
		input.getline(line, 100, ','); //spilt line based on comma (record number)
		int recordNumber = atoi(line); //atoi() converts char * to int
		input.getline(line, 100, ','); //still on the same line split line based on comma (ID)
		int iD = atoi(line);
		char lastName[100] = "";
		input.getline(lastName, 100, ','); //still on the same line split line based on comma (Last Name)
		char firstName[100] = "";
		input.getline(firstName, 100, ','); //still on the same line split line base on comma (First Name)
		string name = string(lastName) + " " + string(firstName); //typecasts the firstName and lastName and concates them
		char email[100] = "";
		input.getline(email, 100, ','); //still on the same line split line based on comma (email)
		char units[100] = "";
		input.getline(units, 100, ','); //still on the same line split line based on comma (units)
		char program[100] = "";
		input.getline(program, 100, ','); //still on the same line split line based on comma (program)
		char level[100] = "";
		input.getline(level, 100); //still on the same line (level)
		int numberOfAbsences = 0;
		vector<string> absenceDates;

		rhs.insertAtFront(recordNumber, iD, name, email, units, program, level, numberOfAbsences, absenceDates);
	}

	return input;
}

/*
Date Created: March 28, 2016
Description: This overload operator << will print the information from the csv file and to the masterfile.
Precondition: The file must be open.
*/
ofstream & operator<< (ofstream & output, const StudentList & rhs)
{
	StudentNode *pCur = rhs.getHeadPtr();

	while (pCur != nullptr)
	{
		output << pCur->getRecordNumber() << endl;
		output << pCur->getID() << endl;
		output << pCur->getName() << endl;
		output << pCur->getEmail() << endl;
		output << pCur->getUnits() << endl;
		output << pCur->getProgram() << endl;
		output << pCur->getLevel() << endl;
		output << pCur->getNumberOfAbsences() << endl;

		// print out the absences
		vector<string> absences = pCur->getAbsenceDates();
		for (string absence : absences)
		{
			output << absence << " ";
		}
		output << "End";

		if (pCur->getNextPtr() != nullptr)
		{
			output << endl;
		}

		pCur = pCur->getNextPtr();
	}

	return output;
}