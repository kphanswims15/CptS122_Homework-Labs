#include "Node.h"

Node::Node(int newData)
{
	mData = newData;

	mpNext = nullptr;
}

Node::Node(const Node & copy)
{
	mData = copy.mData;

	mpNext = copy.mpNext;
}

int Node::getData() const
{
	return mData;
}

Node * Node::getNextPtr() const
{
	return mpNext;
}

void Node::setData(const int newData)
{
	mData = newData;
}

void Node::setNextPtr(Node * const newNext)
{
	mpNext = newNext;
}
