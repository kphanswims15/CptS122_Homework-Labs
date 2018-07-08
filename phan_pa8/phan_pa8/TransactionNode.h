#pragma once

#include <iostream>
#include <string>

#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Date Created: April 22, 2016
Description: This is the TransactionNode class and it publically inherits from the BSTNode class.
*/
class TransactionNode : public BSTNode
{
public:
	// constructor
	TransactionNode(string newData = "", int newUnits = 0);

	// destructor
	~TransactionNode();

	// setter
	void setUnits(const int newUnits);

	// getter
	int getUnits() const;

	void printData();

private:
	int mUnits;
};
