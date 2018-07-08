#include "header.h"

Node * makeNode(int data)
{
	Node * pMem = NULL;
	
	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->data = data;
		pMem->pNext = NULL;
	}

	return pMem;
}

void display(Node * pHead)
{
	if (pHead != NULL)
	{
		while (pHead != NULL)
		{
			printf("Data: %d", pHead->data);
			printf("\n");
			pHead = pHead->data;
		}
	}
}

// Linked List
int isEmpty(Node * pHead)
{
	int num = 0;

	if (pHead == NULL)
	{
		num = 1;
	}

	return num;
}