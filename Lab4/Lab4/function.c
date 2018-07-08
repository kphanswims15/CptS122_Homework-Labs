#include "header.h"

int is_empty(Queue pQ)
{
	int success = 0;

	if (pQ.pHead == NULL)
	{
		success = 1;
	}

	return success;
}

Node * makeNode(char *pNewData)
{
	Node *pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{

	}
}