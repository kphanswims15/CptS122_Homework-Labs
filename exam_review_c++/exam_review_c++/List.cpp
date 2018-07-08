#include "List.h"

List::List()
{
	mpHead = nullptr;
}

List::List(const List & copyList)
{
	this->mpHead = copyList.mpHead;
}

List::~List()
{
	destroyList();
}

Node * List::getHeadPtr() const
{
	return mpHead;
}

void List::setHeadPtr(Node * const newHead)
{
	mpHead = newHead;
}

bool List::insertAtFront(int newData)
{
	bool success = false;

	Node * insertMe = makeNode(newData);
	Node * pCur = mpHead;

	if (pCur == nullptr)
	{
		insertMe->setNextPtr(mpHead);
		mpHead = insertMe;
		success = true;
	}
	else
	{
		insertMe->setNextPtr(mpHead);
		mpHead = insertMe;
		success = true;
	}

	return success;
}

bool List::insertAtBack(int newData)
{
	bool success = false;

	Node * insertMe = makeNode(newData);
	Node * pCur = mpHead;

	if (pCur != nullptr)
	{
		while (pCur->getNextPtr() != nullptr)
		{
			pCur = pCur->getNextPtr();
		}

		pCur->setNextPtr(insertMe);
		success = true;
	}
	else
	{
		insertMe->setNextPtr(mpHead);
		mpHead = insertMe;
		success = true;
	}

	return success;
}

bool List::insertInOrder(int newData)
{
	bool success = false;

	Node * insertMe = makeNode(newData);
	Node * pCur = mpHead;
	Node * pPrev = nullptr;

	if (insertMe != nullptr)
	{
		if (pCur == nullptr)
		{
			mpHead = insertMe;
			success = true;
		}
		else
		{
			while (pCur != nullptr && newData > pCur->getData())
			{
				pPrev = pCur;
				pCur = pCur->getNextPtr();
			}

			if (pCur == nullptr)
			{
				pPrev->setNextPtr(insertMe);
				success = true;
			}
			else if (pPrev != nullptr)
			{
				insertMe->setNextPtr(pCur);
				pPrev->setNextPtr(insertMe);
				success = true;
			}
			else
			{
				insertMe->setNextPtr(mpHead);
				mpHead = insertMe;
				success = true;
			}
		}
	}

	return success;
}

bool List::isEmpty()
{
	bool success = false;

	if (mpHead == nullptr)
	{
		success = true;
		cout << "List is Empty" << endl;
	}

	return success;
}

int List::deleteAtFront()
{
	int data = 0;

	Node *deleteMe = mpHead;

	if (mpHead != nullptr)
	{
		data = deleteMe->getData();
		mpHead = mpHead->getNextPtr();
		delete deleteMe;
	}

	return data;
}

bool List::deleteNode(int search)
{
	bool success = false;

	Node * pPrev = nullptr;
	Node * pCur = mpHead;

	if (mpHead != nullptr)
	{
		while (pCur != nullptr && pCur->getData() != search)
		{
			pPrev = pCur;
			pCur = pCur->getNextPtr();
		}
		
		if (pCur != nullptr)
		{
			if (pPrev != nullptr)
			{
				pPrev->setNextPtr(pCur->getNextPtr());
				delete pCur;
				success = true;
			}
			else
			{
				mpHead = mpHead->getNextPtr();
				delete pCur;
				success = true;
			}
		}
	}

	return success;
}

////////// private data members //////////

Node * List::makeNode(const int newData)
{
	Node * pMem = new Node(newData);

	return pMem;
}

void List::destroyListHelper(Node * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;
	}
}

void List::destroyList()
{
	destroyListHelper(mpHead);
}
