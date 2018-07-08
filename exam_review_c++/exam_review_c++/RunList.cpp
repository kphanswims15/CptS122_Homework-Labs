#include "RunList.h"

void RunList::runApp()
{
	// insert at front
	//mList.insertAtFront(4);
	//mList.insertAtFront(2);
	//mList.insertAtFront(3);

	// insert at back
	/*mList.insertAtBack(5);
	mList.insertAtBack(2);
	mList.insertAtBack(22);*/

	// insert in order
	mList.insertInOrder(22);
	mList.insertInOrder(3);
	mList.insertInOrder(49);

	//int data = mList.deleteAtFront();

	mList.deleteNode(22);

	//cout << "data: " << data << endl;
	cout << mList;

	mList.isEmpty();
}

ostream & operator<<(ostream & output, const List & rhs)
{
	Node * pCur = rhs.getHeadPtr();

	while (pCur != nullptr)
	{
		output << pCur->getData() << endl;

		pCur = pCur->getNextPtr();
	}

	return output;
}