#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "StudentList.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios;

/*
Date Created: March 9, 2016
Description: Runs the whole application and contains all the files.
*/
class RunApp
{
public:
	void runApp();
	void loadStudents(ifstream & fileStream, StudentList & students);
	void outputStudents(ofstream & fileStream, StudentList & students);
	void readFromMasterList(ifstream & fileStream, StudentList & students);
	void printToMasterList(ofstream & fileStream, StudentList & students);
	void markAbsences(StudentList & student);
	void reportWrapper(ofstream & report1, ofstream & report2, ofstream & report3, StudentList & students);
	void generateReportsForAllStudents(ofstream & outFileStream, StudentList & students);
	void generateReportsForStudentsThatMatchOrExceed(ofstream & fileStream, StudentList & students, int numberOfAbsences);
	void generateDateReport(ofstream & fileStream, StudentList & students, string date);
	void displaySubMenu();
	void displayMenu();

private:
	StudentList mList;
};

ifstream & operator>> (ifstream &input, StudentList & student);
ofstream & operator<< (ofstream & output, const StudentList &rhs);