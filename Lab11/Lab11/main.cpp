#include "List.h"

int main(void)
{
	List<int> myList;

	myList.insertAtFront(5);
	myList.insertAtFront(99);
	myList.insertAtBack(200);
	myList.insertAtBack(300);
	myList.print();

	return 0;
}