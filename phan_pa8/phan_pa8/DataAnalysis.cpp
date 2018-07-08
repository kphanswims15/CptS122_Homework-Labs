#include "DataAnalysis.h"

/*
Date Created: April 23, 2016
Description: This runs the whole program.
*/
void DataAnalysis::runAnalysis()
{
	openFile();
	readFile();
	writeToScreen();
	mCsvStream.close();
}

/*
Date Created: April 23 2016
Description: This opens up the file.
*/
void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
}

/*
Date Created: April 23, 2016
Description: This reads a line from the data csv file.
*/
void DataAnalysis::readline()
{
	char line[100] = "";

	mCsvStream.getline(line, 100, ',');
	int units = atoi(line);
	mCsvStream.getline(line, 100, ',');
	string data = line;
	mCsvStream.getline(line, 100);
	string transaction = line;

	createdTrees(units, data, transaction);
}

/*
Date Created: April 23, 2016
Description: This will read the whole file.
*/
void DataAnalysis::readFile()
{
	if (mCsvStream.is_open())
	{
		char line[100] = "";
		mCsvStream.getline(line, 100);

		while (!mCsvStream.eof())
		{
			readline();
			cout << "Purchased Tree" << endl;
			mTreePurchased.inOrderTraversal();
			cout << endl << "Sold Tree" << endl;
			mTreeSold.inOrderTraversal();
			system("pause");
			system("cls");
		}
	}
	else
	{
		cout << "Your file could not be opened" << endl;
	}
}

/*
Date Created: April 23, 2016
Description: This will sort the trees and inserts them into the correct tree.
*/
void DataAnalysis::createdTrees(const int newUnits, const string newData, const string newTransaction)
{
	if (newTransaction == "Purchased")
	{
		mTreePurchased.insert(newData, newUnits);
	}
	else
	{
		mTreeSold.insert(newData, newUnits);
	}
}

/*
Date Created: April 23, 2016
Description: This will print out to the screen the smallest and largest node.
*/
void DataAnalysis::writeToScreen()
{
	cout << "Purchased Tree" << endl;
	cout << "Smallest unit:" << endl;
	mTreePurchased.findSmallest(mTreePurchased.getRoot()).printData();
	cout << "Largest units:" << endl;
	mTreePurchased.findLargest(mTreePurchased.getRoot()).printData();
	cout << endl << "Sold Tree" << endl;
	cout << "Smallest units:" << endl;
	mTreeSold.findSmallest(mTreePurchased.getRoot()).printData();
	cout << "Largest unit:" << endl;
 	mTreeSold.findLargest(mTreeSold.getRoot()).printData();
}
