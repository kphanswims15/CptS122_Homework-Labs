/*
advanced data types vs data structures
- adt is specific and data structures is for implementation

self-referential structures
- nodes, stacks and queeus

malloc() and free()
- malloc is used to allocate memory
- free is used to deallocate memory

compare and contrast linked lists, stacks, and queues
- linked list is a linear list that can go through the whole list
- stacks is last in first out - example: stack of plates
- queues is first in first out - example: grocery line
*/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node
{
	int data;
	struct node *pNext;
}Node;

//void run_app(void);
Node *makeNode(int data);
void display(Node *pHead);

// Linked List
int isEmpty(Node *pHead);

#endif