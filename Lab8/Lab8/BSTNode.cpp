#include "BSTNode.h"

BSTNode::BSTNode(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

string BSTNode::getData() const
{
	return mData;
}

BSTNode *& BSTNode::getLeft()
{
	return mpLeft;
}

BSTNode *& BSTNode::getRight()
{
	return mpRight; 
}

void BSTNode::setData(const string newData)
{
	mData = newData;
}

void BSTNode::setLeft(BSTNode * const newLeft)
{
	mpLeft = newLeft;
}

void BSTNode::setRight(BSTNode * const newRight)
{
	mpRight = newRight;
}
