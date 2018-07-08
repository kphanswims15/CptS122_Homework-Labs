#include "BST.h"

/*
Date Created: April 23, 2016 
Description: This is a constructor for the BST class it sets the mRoot to nullptr
*/
BST::BST()
{
	mpRoot = nullptr;
}

/*
Date Created: April 23, 2016
Description: This is a destructro that deallocates memory for the tree. It calls destroy tree to help
		to deallocate the memory.
*/
BST::~BST()
{
	destroyTree(mpRoot);
}

/*
Date Created: April 23, 2016
Description: This is a setter and this mutates the mpRoot.
*/
void BST::setRoot(BSTNode * const newRoot)
{
	mpRoot = newRoot;
}

/*
Date Created: April 23, 2016
Description: This is a getter and this returns a copy of the mpRoot.
*/
BSTNode *& BST::getRoot()
{
	return mpRoot;
}

/*
Date Created: April 23, 2016
Description: This is the insert function that inserts the node into the tree. It calls a private insert function.
*/
void BST::insert(const string newData, const int newUnits)
{
	insert(mpRoot, newData, newUnits);
}

/*
Date Created: April 23, 2016
Description: This prints out the whole tree in order. It calls the private function inOrderTraversal.
*/
void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

/*
Date Created: April 23, 2016
Description: This finds the smallest node in the tree.
*/
TransactionNode & BST::findSmallest(BSTNode *& pTree)
{
	TransactionNode  *pMem = nullptr;

	if (pTree->getLeft() == nullptr)
	{
		pMem = dynamic_cast <TransactionNode *> (pTree);
		return *pMem;
	}
	else
	{
		findSmallest(pTree->getLeft());
	}
}

/*
Date Created: April 23, 2016
Description: This finds the largest node in the tree.
*/
TransactionNode & BST::findLargest(BSTNode *& pTree)
{
	TransactionNode *pMem = nullptr;

	if (pTree->getRight() == nullptr)
	{
		pMem = dynamic_cast <TransactionNode *> (pTree);
		return *pMem;
	}
	else
	{
		findLargest(pTree->getRight());
	}
}

////////// private data members //////////

/*
Date Created: April 23, 2016
Description: This is the destroy tree helper and it goes through the whole tree recursively and
		deallocates the memory.
*/
void BST::destroyTree(BSTNode * n)
{
	if (n != nullptr)
	{
		// this is preforming a postorder traversal to delete the nodes.
		destroyTree(n->getLeft()); // go left
		destroyTree(n->getRight()); // go right
		delete(n); // process node
	}
}

/*
Date Created: April 23, 2016
Description: This allocates memory for the TransactionNode
*/
BSTNode * BST::makeNode(const string newData, const int newUnits)
{
	BSTNode * pMem = new TransactionNode(newData, newUnits);

	return pMem;
}

/*
Date Created: April 23, 2016
Description: This inserts the node into the tree and it is a helper for insert node.
*/
void BST::insert(BSTNode *& pTree, const string newData, const int newUnits)
{
	if (pTree == nullptr) // checking to see if tree is empty, or if the subtree is empty
	{
		// insert a node into the tree
		BSTNode * pMem = makeNode(newData, newUnits);
		pTree = pMem;
	}
	else // recursive step
	{
		if (newUnits < dynamic_cast <TransactionNode *> (pTree)->getUnits()) // pTree points to current node
		{
			insert(pTree->getLeft(), newData, newUnits);
		}
		else if (newUnits > dynamic_cast <TransactionNode *> (pTree)->getUnits()) // pTree points to the current node
		{
			insert(pTree->getRight(), newData, newUnits);
		}
	}
}

/*
Date Created: April 23, 2016
Description: This prints out the node and it is the inOrderTraversal helper. It prints the nodes in order.
*/
void BST::inOrderTraversal(BSTNode * pTree)
{
	if (pTree != nullptr)
	{
		// go left
		inOrderTraversal(pTree->getLeft());
		// process node
		dynamic_cast <TransactionNode *> (pTree)->printData();
		// go right
		inOrderTraversal(pTree->getRight());
	}
}
