#include "BSTNode.h"

/*
Date Created: April 22, 2016
Description: This is a constructor for the BSTNode class.
*/
BSTNode::BSTNode(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

/*
Date Created: April 22, 2016
Description: This is a virtual destructor.
*/
BSTNode::~BSTNode()
{

}

/*
Date Created: April 22, 2016
Description: This is a setter. It will modify the protected data members in the object.
*/
void BSTNode::setData(const string newData)
{
	mData = newData;
}

/*
Date Created: April 22, 2016
Description: This is a setter. It will modify the protected data members in the object.
*/
void BSTNode::setLeft(BSTNode * const newLeft)
{
	mpLeft = newLeft;
}

/*
Date Created: April 22, 2016
Description: This is a setter. It will modify the protected data members in the object.
*/
void BSTNode::setRight(BSTNode * const newRight)
{
	mpRight = newRight;
}

/*
Date Created: April 22, 2016
Description: This is a getter. It will get access to a copy of the protected data members in the object.
*/
string BSTNode::getData() const
{
	return mData;
}

/*
Date Created: April 22, 2016
Description: This is a getter. It will get access to a copy of the protected data members in the object.
*/
BSTNode *& BSTNode::getLeft()
{
	return mpLeft;
}

/*
Date Created: April 22, 2016
Description: This is a getter. It will get access to a copy of the protected data members in the object.
*/
BSTNode *& BSTNode::getRight()
{
	return mpRight;
}
