#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Date Created: March 21, 2016
Description: This class holds all the information for the BSTNode.
*/
class BSTNode
{
public:
	// constructor
	BSTNode(char newLetter = '\0', string newMorse = "");

	// destructor
	~BSTNode();

	// getters
	char getLetter() const;
	string getMorse() const;
	BSTNode *& getLeft();
	BSTNode *& getRight();

	// setters
	void setLetter(const int newLetter);
	void setMorse(const string newMorse);
	void setLeft(BSTNode * const newLeft);
	void setRight(BSTNode * const newRight);

private:
	char mLetter;
	string mMorse;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};