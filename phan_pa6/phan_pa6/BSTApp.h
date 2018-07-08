#pragma once

#include <iostream>
#include <fstream>

#include "BSTNode.h"
#include "BST.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

/*
Date Created: March 21, 2016
Date Last Modified: March 22, 2016
Description: This runs the whole app and puts it all together.
*/
class BSTApp
{
public:
	// constructor
	BSTApp();

	// destructor
	~BSTApp();

	void runApp(void);

private:
	ifstream mInputStream; // the file is associated with "MorseTable.txt"
	ifstream mReadConvert; // the file is associated with "Convert.txt"
	BST mTree; // this is a sequence constainer
};
