#pragma once

#include <iostream>
#include <string>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class List
{
public:
	List();
	
	List(const List &copyList);

	~List();

	Node * getHeadPtr() const;

	void setHeadPtr(Node * const newHead);

	bool insertAtFront(int newData);
	bool insertAtBack(int newData);
	bool insertInOrder(int newData);
	bool isEmpty();
	int deleteAtFront();
	bool deleteNode(int search);

private:
	Node *mpHead;

	Node *makeNode(const int newData);
	void destroyListHelper(Node * const pMem);
	void destroyList();
};
