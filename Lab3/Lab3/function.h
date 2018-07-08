#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	double data;
	struct node *pNext;
}Node;

enum bool
{
	TRUE,
	FALSE
}Bool;

Node * makeNode(double data);
int isEmpty(Node *pTop);
void push(Node **pTop, double data);
void print_list(Node *pTop);
void pop(Node **pTop);
double peek(Node *pTop);