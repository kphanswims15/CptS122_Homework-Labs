#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BSTNode
{
public:
	BSTNode(string newData = "");

	string getData() const;
	BSTNode *& getLeft();
	BSTNode *& getRight();

	void setData(const string newData);
	void setLeft(BSTNode * const newLeft);
	void setRight(BSTNode * const newRight);

private:
	string mData;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};