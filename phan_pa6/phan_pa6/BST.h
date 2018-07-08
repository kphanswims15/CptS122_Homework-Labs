#pragma once

#include <iostream>
#include <fstream>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

/*
Date Created: March 21, 2016
Date Last Modified: March 22, 2016
Description: This creates a tree of BST Nodes
*/
class BST
{
public:
	// constructor
	BST();

	// copy constructor
	BST(const BST &rhs);

	// destructor
	~BST();

	// getter
	BSTNode *getRoot() const;

	//setter
	void setRoot(BSTNode * const newRoot);

	void insert(const char newLetter, const string newMorse);
	void print();
	void search(const char searchLetter);

private:
	BSTNode *mpRoot;
	ifstream mInputStream;

	void destroyTree(BSTNode * n);
	BSTNode * makeNode(const char newLetter, const string newMorse);
	void insert(BSTNode *& pTree, const char newLetter, const string newMorse);
	void print(BSTNode * pTree);
	void search(BSTNode * pTree, const char searchLetter);
};

ifstream & operator>> (ifstream & input, BST & rhs);