#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::string;

class Node
{
public:
	Node(int newData = 0);

	Node(const Node & copy);

	int getData() const;
	Node * getNextPtr() const;

	void setData(const int newData);
	void setNextPtr(Node * const newNext);

private:
	int mData;
	Node * mpNext;
};
