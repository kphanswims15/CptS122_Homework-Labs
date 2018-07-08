/**************************************************************************
* Date Created: February 8, 2016                                          *
* Date Last Modified: 
* Description: Holds defines and standard libraries and function headers. *
***************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct queueNode
{
	int customerNumber; //Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; //Random time; varies between express and normal lanes; units in minutes
	int totalTime; //totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
	struct queueNode *pNext;
}QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
}Queue;

void run_app(void);
int random_time_express(void);
int random_time_normal(void);
QueueNode *makeCustomer(int customerNumber, int serviceTime, int totalTime);
void enqueue(Queue *pQ, int customerNumber, int serviceTime, int totalTime);
void dequeue(Queue *pQ); 
void printQueue(Queue pQ);
int total_time(Queue pQ);
int isEmpty(Queue pQ);

#endif