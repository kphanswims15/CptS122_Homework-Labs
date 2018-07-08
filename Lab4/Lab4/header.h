#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *data;
	struct node *pNext;
}Node;

typedef struct queue
{
	Node *pHead;
	Node *pTail;
}Queue;

int is_empty(Queue pQ);
Node * makeNode(char *pNewData);