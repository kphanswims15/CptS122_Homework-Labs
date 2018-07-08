#include "BSTNode.h"

/*
Date Created: March 21, 2016
Description: This is the constructor for the BSTNode class.
*/
BSTNode::BSTNode(char newLetter, string newMorse)
{
	mLetter = newLetter;
	mMorse = newMorse;
	mpLeft = nullptr;
	mpRight = nullptr;
}

/*
Date Created: March 21, 2016
Description: This is the destructor.
*/
BSTNode::~BSTNode()
{

}

/*
Date Created: March 21, 2016
Description: This is a getter that will get access to a copy of the private data members
		in the object.
*/
char BSTNode::getLetter() const
{
	return mLetter;
}

/*
Date Created: March 21, 2016
Description: This is a getter that will get access to a copy of the private data members
		in the object.
*/
string BSTNode::getMorse() const
{
	return mMorse;
}

/*
Date Created: March 21, 2016
Description: This is a getter that will get access to a copy of the private data members
		in the object.
*/
BSTNode *& BSTNode::getLeft()
{
	return mpLeft;
}

/*
Date Created: March 21, 2016
Description: This is a getter that will get access to a copy of the private data members
		in the object.
*/
BSTNode *& BSTNode::getRight()
{
	return mpRight;
}

/*
Date Created: March 21, 2016
Description: This is a setter the modifys the priveate data member in the object.
*/
void BSTNode::setLetter(const int newLetter)
{
	mLetter = newLetter;
}

/*
Date Created: March 21, 2016
Description: This is a setter that will modify the private data members in the object.
*/
void BSTNode::setMorse(const string newMorse)
{
	mMorse = newMorse;
}

/*
Date Created: March 21, 2016
Description: This is a setter that will modify the private data members in the object.
*/
void BSTNode::setLeft(BSTNode * const newLeft)
{
	mpLeft = newLeft;
}

/*
Date Created: March 21, 2016
Description: This is a setter that will modify the private data members in the object.
*/
void BSTNode::setRight(BSTNode * const newRight)
{
	mpRight = newRight;
}
