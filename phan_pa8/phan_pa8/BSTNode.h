#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Date Created: April 22, 2016
Description: This class holds all the information for the BSTNode and it is an abstract class.
*/
class BSTNode
{
public:
	// constructor
	BSTNode(string newData = "");

	// destructor
	virtual ~BSTNode();

	// setters
	void setData(const string newData);
	void setLeft(BSTNode * const newLeft);
	void setRight(BSTNode * const newRight);

	// getters 
	string getData() const;
	BSTNode *& getLeft();
	BSTNode *& getRight();

	// pure virtual function will over write in TransactionNode
	virtual void printData() = 0;

protected:
	string mData;
	BSTNode * mpLeft;
	BSTNode * mpRight;
};
