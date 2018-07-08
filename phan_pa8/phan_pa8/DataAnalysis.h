#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/*
Date Created: April 23, 2016
Description: This is the DataAnalysis class and it wraps up the whole program.
*/
class DataAnalysis
{
public:
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile();
	void readline();
	void readFile();
	void createdTrees(const int newUnits, const string newData, const string newTransaction);
	void writeToScreen();
};