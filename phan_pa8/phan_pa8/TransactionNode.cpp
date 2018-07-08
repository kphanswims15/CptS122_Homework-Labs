#include "TransactionNode.h"

/*
Date Created: April 22, 2016
Description: This is a constructor. It publically inherits from the BSTNode constructor to created the object.
*/
TransactionNode::TransactionNode(string newData, int newUnits) : BSTNode(newData)
{
	mUnits = newUnits;
}

/*
Date Created: April 22, 2016
Description: This is a destructor. It does nothing.
*/
TransactionNode::~TransactionNode()
{

}

/*
Date Created: April 22, 2016
Description: This is a setter and it will modify the private data members in the object.
*/
void TransactionNode::setUnits(const int newUnits)
{
	mUnits = newUnits;
}

/*
Date Created: April 22, 2016
Description: This is a getter and it provides a copy of the private data members in the object.
*/
int TransactionNode::getUnits() const
{
	return mUnits;
}

/*
Date Created: April 22, 2016
Description: This will print out the contents in the TransactionNode it will also overwrite the 
		print function in the BSTNode Class.
*/
void TransactionNode::printData()
{
	cout << this->mData << endl;
	cout << this->mUnits << endl;
}
