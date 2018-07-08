#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template< class NODETYPE > class List;  // forward declaration

template<class NODETYPE>
class ListNode
{
	friend class List< NODETYPE >; // make List a friend
public:
	ListNode(const NODETYPE &newData);  // constructor
	NODETYPE getData() const;      // return data in the node

private:
	NODETYPE data;                 // data
	ListNode< NODETYPE > *nextPtr; // next node in the list
};

template< class NODETYPE >
class List
{
public:
	List();      // constructor
	~List();     // destructor
	void insertAtFront(const NODETYPE &newData);
	void insertAtBack(const NODETYPE &newData);
	bool removeFromFront(NODETYPE &removedData);
	bool removeFromBack(NODETYPE &removedData);
	bool isEmpty() const;
	void print() const;

private:
	ListNode< NODETYPE > *firstPtr;  // pointer to first node
	ListNode< NODETYPE > *lastPtr;   // pointer to last node
	// Utility function to allocate a new node
	ListNode< NODETYPE > *getNewNode(const NODETYPE &newData);
};

template<class NODETYPE>
inline List<NODETYPE>::List()
{
	firstPtr = nullptr;
	lastPtr = nullptr;
}

template<class NODETYPE>
inline List<NODETYPE>::~List()
{

}

template<class NODETYPE>
inline void List<NODETYPE>::insertAtFront(const NODETYPE & newData)
{
	ListNode<NODETYPE> * pMem = getNewNode(newData);

	if (pMem != nullptr)
	{
		pMem->nextPtr = firstPtr;
		firstPtr = pMem;
	}
}

template<class NODETYPE>
inline void List<NODETYPE>::insertAtBack(const NODETYPE & newData)
{
	ListNode<NODETYPE> * pMem = getNewNode(newData);
	ListNode<NODETYPE> * pCur = firstPtr;

	if (pMem != nullptr)
	{
		if (pCur == nullptr)
		{
			firstPtr = pMem;
			lastPtr = pMem->nextPtr;
		}
		else
		{
			while (pCur->nextPtr != nullptr)
			{
				pCur = pCur->nextPtr;
			}

			pCur->nextPtr = pMem;
			pMem->nextPtr = lastPtr;
		}
	}
}

template<class NODETYPE>
inline bool List<NODETYPE>::removeFromFront(NODETYPE & removedData)
{
	bool success = false;

	if (firstPtr != nullptr)
	{
		success = true;
		removedData = firstPtr->getData();
		delete firstPtr->getData();
	}

	return success;
}

template<class NODETYPE>
inline bool List<NODETYPE>::removeFromBack(NODETYPE & removedData)
{
	bool success = false;

	ListNode<NODETYPE> * pCur = firstPtr;
	ListNode<NODETYPE> * pPrev = nullptr;

	while (pCur != nullptr)
	{
		pPrev = pCur;
		pCur = pCur->nextPtr;
		success = true;
	}

	if (pCur != firstPtr)
	{
		removedData = pCur->getData();
		delete pCur;
		pPrev->nextPtr = nullptr; 
	}
	else
	{
		removedData = pCur->getData();
		delete pCur;
		firstPtr = nullptr;
		success = true;
	}
		
	return success;
}

template<class NODETYPE>
inline bool List<NODETYPE>::isEmpty() const
{
	bool success = false;

	if (firstPtr == nullptr && lastPtr == nullptr)
	{
		success = true;
	}

	return success;
}

template<class NODETYPE>
inline void List<NODETYPE>::print() const
{
	ListNode<NODETYPE> *pCur = firstPtr;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->nextPtr;
	}
}

template<class NODETYPE>
inline ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE & newData)
{
	ListNode<NODETYPE> * pMem = new ListNode<NODETYPE>(newData);
	
	return pMem;
}

template<class NODETYPE>
inline ListNode<NODETYPE>::ListNode(const NODETYPE & newData)
{
	data = newData;
	nextPtr = nullptr;
}

template<class NODETYPE>
inline NODETYPE ListNode<NODETYPE>::getData() const
{
	return data;
}
