#include "BST.h"

/*
Date Created: March 21, 2016
Description: This is a constructor for the BST class it sets the mRoot to nullptr.
*/
BST::BST()
{
	mpRoot = nullptr;
}

/*
Date Created: March 21, 2016
Description: This is a copy constructor for the BST class and it copies the mpRoot.
*/
BST::BST(const BST & rhs)
{
	this->mpRoot = rhs.mpRoot;
}

/*
Date Created: March 21, 2016
Description: This a destructor that deallocates memory for the tree.
*/
BST::~BST()
{
	destroyTree(mpRoot);
}

/*
Date Created: March 21, 2016
Description: This is a getter to get access to the private mpRoot.
*/
BSTNode * BST::getRoot() const
{
	return mpRoot;
}

/*
Date Created: March 21, 2016
Description: This is the setter and this mutates the mpRoot.
*/
void BST::setRoot(BSTNode * const newRoot)
{
	mpRoot = newRoot;
}

/*
Date Created: March 21, 2016 
Description: This is the insert function that inserts the node into the tree.
*/
void BST::insert(const char newLetter, const string newMorse)
{
	insert(mpRoot, newLetter, newMorse);
}

/*
Date Created: March 21, 2016 
Description: This prints out the whole tree in alphabetical order.
*/
void BST::print()
{
	print(mpRoot);
}

/*
Date Created: March 22, 2016
Description: This searches for a letter and prints out the contents in the BSTNode.
*/
void BST::search(const char searchLetter)
{
	search(mpRoot, searchLetter);
}

////////// private member functions //////////

/*
Date Created: March 21, 2016
Description: This is the destroy tree helper and it goes through the whole tree recursively and 
		deallocates the memory.
*/
void BST::destroyTree(BSTNode * n)
{
	if (n != nullptr)
	{
		// this is preforming a postorder traversal to delete the nodes.
		destroyTree(n->getLeft()); // 1. go left
		destroyTree(n->getRight()); // 2. go right
		delete(n); // 3. process node
	}
}

/*
Date Created: March 21, 2016
Description: This allocates memory for the BSTNode. 
*/
BSTNode * BST::makeNode(const char newLetter, const string newMorse)
{
	BSTNode *pMem = new BSTNode(newLetter, newMorse); //constructing a BSTNode on the heap
	
	return pMem;
}

/*
Date Created: March 21, 2016
Description: This inserts the node into the tree and it is a helper for insert node.
*/
void BST::insert(BSTNode *& pTree, const char newLetter, const string newMorse)
{
	if (pTree == nullptr) // checking to see if tree is empty, or if the subtree is empty
	{
		// insert a node into the tree
		BSTNode *pMem = makeNode(newLetter, newMorse); // we have node on the heap
		pTree = pMem;
	}
	else // recursive step
	{
		if (newLetter < pTree->getLetter()) // pTree points to current node
		{
			insert(pTree->getLeft(), newLetter, newMorse);
		}
		else if (newLetter > pTree->getLetter()) // pTree points to current node
		{
			insert(pTree->getRight(), newLetter, newMorse);
		}
	}
}

/*
Date Created: March 21, 2016
Description: This is the print node helper and it does and inOrderTraversal to print out the node
*/
void BST::print(BSTNode * pTree)
{
	if (pTree != nullptr)
	{
		// 1. go left
		print(pTree->getLeft());
		// 2. process node
		cout << "Character: " << pTree->getLetter() << endl;
		cout << "Morse: " << pTree->getMorse() << endl;
		// 3. go right
		print(pTree->getRight());
	}
}

/*
Date Created: March 22, 2016
Description: This does a postOrderTraversal and it returns all morse characters to the letters the match.
*/
void BST::search(BSTNode * pTree, const char searchLetter)
{
	if (pTree != nullptr && searchLetter != pTree->getLetter())
	{
		// 1. go left
		search(pTree->getLeft(), searchLetter);
		// 2. go right
		search(pTree->getRight(), searchLetter);
	}

	if (pTree != nullptr && searchLetter == pTree->getLetter())
	{
		// 3. process node
		cout << pTree->getMorse() << " ";
	}
}

////////// non-member function //////////

/*
Date Created: March 21, 2016
Description: This is an overloaded operator that reads from the morse table text file.
*/
ifstream & operator>>(ifstream & input, BST & rhs)
{
	char letter = '\0';
	string morse = "";

	while (!input.eof())
	{
		input >> letter;
		input >> morse;

		rhs.insert(letter, morse);
	}

	return input;
}
