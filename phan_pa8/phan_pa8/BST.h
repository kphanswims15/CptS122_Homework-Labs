#pragma once

#include <iostream>
#include <string>

#include "TransactionNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Date Created: April 23, 2016
Descripton: This creates a tree of TransactionNodes
*/
class BST
{
public:
	// constructor
	BST();

	// destructor
	~BST();

	// setter
	void setRoot(BSTNode * const newRoot);

	// getter
	BSTNode *& getRoot();

	void insert(const string newData, const int newUnits);
	void inOrderTraversal();
	TransactionNode & findSmallest(BSTNode *& pTree);
	TransactionNode & findLargest(BSTNode *& pTree);

private:
	BSTNode * mpRoot;

	void destroyTree(BSTNode * n);
	BSTNode * makeNode(const string newData, const int newUnits);
	void insert(BSTNode *& pTree, const string newData, const int newUnits);
	void inOrderTraversal(BSTNode *pTree);
};