#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BSTNode * BST::getRoot() const
{
	return mpRoot;
}

void BST::setRoot(BSTNode * const newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(const string newData)
{
	insert(mpRoot, newData);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::preOrderTraversal()
{
	preOrderTraversal(mpRoot);
}

///////////////Private///////////////
BSTNode * BST::makeNode(const string newData)
{
	BSTNode *pMem = new BSTNode(newData);

	return pMem;
}

void BST::insert(BSTNode *& pTree, const string newData)
{
	if (pTree == nullptr)
	{
		BSTNode *pMem = makeNode(newData);
		pTree = pMem;
	}
	else
	{
		if (newData < pTree->getData())
		{
			return insert(pTree->getLeft(), newData);
		}
		else if (newData > pTree->getData())
		{
			return insert(pTree->getRight(), newData);
		}
	}
}

void BST::inOrderTraversal(BSTNode * pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		cout << "Data: " << pTree->getData() << endl;
		inOrderTraversal(pTree->getRight());
	}
}

void BST::preOrderTraversal(BSTNode * pTree)
{
	if (pTree != nullptr)
	{
		cout << "Data: " << pTree->getData() << endl;
		preOrderTraversal(pTree->getLeft());
		preOrderTraversal(pTree->getRight());
	}
}
