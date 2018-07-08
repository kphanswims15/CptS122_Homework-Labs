#include "function.h"

Node * makeNode(double data)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	pMem->pNext = NULL;
	pMem->data = data;

	return pMem;
}

int isEmpty(Node * pTop)
{
	enum bool check;

	if (pTop == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void push(Node ** pTop, double data)
{
	enum bool check;
	Node *pTemp = NULL;

	if (*pTop == NULL)
	{
		*pTop = makeNode(data);
	}
	else
	{
		pTemp = *pTop;
		*pTop = makeNode(data);
		(*pTop)->pNext = pTemp;
	}
}

void print_list(Node *pTop)
{
	while (pTop != NULL)
	{
		printf("--> %.2lf", pTop->data);
		pTop = pTop->pNext;
	}

	printf("-->\n");
}

void pop(Node ** pTop)
{
	Node *pTemp = NULL;

	if (*pTop != NULL)
	{
		pTemp = (*pTop)->pNext;
		free(*pTop);
		*pTop = pTemp;
	}
	else
	{
		printf("List is empty.\n");
	}
}

double peek(Node * pTop)
{
	double num = 0.0;

	num = pTop->data;

	return num;
}
