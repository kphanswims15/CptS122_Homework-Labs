#include "functions.h"

/*
Function: void run_app(void)
Date Created: February 8, 2016
Date Last Modified: February 11, 2016
Description: Runs the whole simulation.
Input Parameters: None
Returns: None.
Preconditions: Other functions and something has to be inside this function in order to run.
Postconditions: The simulation runs.
*/
void run_app(void)
{
	int service_time_express = 0, service_time_normal = 0, arrival_time_express = 0, arrival_time_normal = 0, counter_time = 0, user_input = 0;
	int customer_express = 1, customer_normal = 1, total_express = 0, total_normal = 0, delete_express = 0, delete_normal = 0;
	
	Queue pQ = { NULL, NULL };
	Queue pQ2 = { NULL, NULL };

	srand((unsigned int) time(NULL));

	printf("Welcome to the line simulator!\n");
	printf("Enter the time you want the simulator (minutes): ");
	scanf("%d", &user_input);
	system("pause");
	system("cls");


	arrival_time_express = random_time_express();
	arrival_time_normal = random_time_normal();

	while (counter_time <= user_input)
	{
		if (arrival_time_express == 0)
		{
			printf("Custumer %d has entered the express line.\n", customer_express);
			service_time_express = random_time_express();
			total_express = total_time(pQ) + service_time_express;
			enqueue(&pQ, customer_express, service_time_express, total_express);
			arrival_time_express = random_time_express();
			customer_express++;
		}

		if (arrival_time_normal == 0)
		{
			printf("Customer %d has entered the normal line.\n", customer_normal);
			service_time_normal = random_time_normal();
			total_normal = total_time(pQ2) + service_time_normal;
			enqueue(&pQ2, customer_normal, service_time_normal, total_normal);
			arrival_time_normal = random_time_normal();
			customer_normal++;
		}

		if (pQ.pHead != NULL && pQ.pTail != NULL)
		{
			if (pQ.pHead->serviceTime == 0)
			{
				printf("Customer %d has left the express line.\n", pQ.pHead->customerNumber);
				dequeue(&pQ);
			}
		}

		if (pQ2.pHead != NULL && pQ2.pTail != NULL)
		{
			if (pQ2.pHead->serviceTime == 0)
			{
				printf("Customer %d has left the normal line.\n", pQ2.pHead->customerNumber);
				dequeue(&pQ2);
			}
		}

		if (counter_time % 10 == 0)
		{
			printf("\n");
			printf("Express line: \n");
			printQueue(pQ);
			printf("\n");
			printf("Normal line: \n");
			printQueue(pQ2);
			system("pause");
			system("cls");
		}

		arrival_time_express--;
		arrival_time_normal--;

		if (pQ.pHead != NULL && pQ.pTail != NULL)
		{
			pQ.pHead->serviceTime--;
		}

		if (pQ2.pHead != NULL && pQ2.pTail != NULL)
		{
			pQ2.pHead->serviceTime--;
		}

		if (counter_time % 1440 == 0)
		{
			while (isEmpty(pQ) != 1)
			{
				dequeue(&pQ);
			}

			while (isEmpty(pQ2) != 1)
			{
				dequeue(&pQ2);
			}

			customer_express = 1;
			customer_normal = 1;
		}

		counter_time++;
	}
}

/*
Function: int random_time_express(void)
Date Created: February 8, 2016
Date Last Modified: February 8, 2016
Description: Generates a time between 1 - 5 for the express line.
Input Parameters: None.
Returns: int time
Preconditions: A variable has to be declared to save the random number generated.
Postconditions: A number between 1 - 5 has been generated.
*/
int random_time_express(void) 
{
	int time = 0;

	time = rand() % 5 + 1;

	return time;
}

/*
Function: int random_time_normal(void)
Date Created: February 8, 2016
Date Last Modified: February 8, 2016
Description: Generates a random number between 3 - 8 for the normal line.
Input Parameters: None.
Returns: int time
Preconditions: A variable has to exist to hold the random generated time.
Postconditions: A number is generated between 3 - 8.
*/
int random_time_normal(void)
{
	int time = 0;
	
	time = rand() % (8 - 3 + 1) + 3;

	return time;
}

/*
Function: QueueNode * makeCustomer(int customerNumber, int serviceTime, int TotalTime)
Date Created: February 8, 2016
Date Last Modified: February 8, 2016
Description: Aquires total memeory for each customer when it is created.
Input Parameters: int customerNumber, int serviceTime, int totalTime
Returns: A QueueNode * type.
Preconditions: A struct for QueueNode has to be created and the customer number, service time, and the total time must exist.
Postconditions: Memory has been allocated for a customer.
*/
QueueNode * makeCustomer(int customerNumber, int serviceTime, int totalTime)
{
	QueueNode * pMem = NULL;

	pMem = (QueueNode *)malloc(sizeof(QueueNode));

	pMem->pNext = NULL;
	pMem->customerNumber = customerNumber;
	pMem->serviceTime = serviceTime;
	pMem->totalTime = totalTime;
	
	return pMem;
}

/*
Function: void enqueue(Queue * pQ, int customerNumber, int serviceTime, int totalTime)
Date Created: February 8, 2016
Date Last Modified: February 8, 2016
Description: Add a new customer at the end of the list of customers.
Input Parameters: Queue * pQ, int customerNumber, int serviceTime, int totalTime
Precondtions: A struct that holds the lists pHead and pTail, int customerNumber, int serviceTime, and int totalTime need to exist.
Returns: None
Postcondtions: A customer is successfully added at the end of the list.
*/
void enqueue(Queue * pQ, int customerNumber, int serviceTime, int totalTime)
{
	QueueNode * pMem = makeCustomer(customerNumber, serviceTime, totalTime);

	if (pMem != NULL)
	{
		if (pQ->pHead != NULL)
		{
			//queue is not empty
			pQ->pTail->pNext = pMem;
			pQ->pTail = pMem;
		}
		else
		{
			//queue is empty
			pQ->pHead = pQ->pTail = pMem;
		}
	}
}

/*
Function: void dequeue(Queue * pQ)
Date Created: February 8, 2016
Date Last Modified: February 9, 2016
Description: Deletes the customer at the front of the line when the service time is up.
Input Parameters: Queue * pQ
Returns: None
Precondtions: A struct that holds the lists pHead and pTail need to exist.
Postconditions: A customer is successfully deallocated from the list.
*/
void dequeue(Queue * pQ)
{
	QueueNode *pCur = pQ->pHead;

	if (pQ->pHead == pQ->pTail)
	{
		//one node
		pQ->pHead = pQ->pTail = NULL;
	}
	else
	{
		//more than one node
		pQ->pHead = pQ->pHead->pNext;
	}

	free(pCur);
}

/*
Function: void printQueue(Queue)
Date Created: February 8, 2016
Date Last Modified: February 10, 2016
Description: Prints out what is in the Queue after 10 minutes.
Input Parameters: Queue pQ
Returns: None
Preconditions: A struct holding the pHead and pTail needs to exist.
Postconditions: The whole list is displayed.
*/
void printQueue(Queue pQ)
{
	QueueNode *pCur = pQ.pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL)
		{
			printf("Customer: %d\n", pCur->customerNumber);
			printf("Service Time: %d\n", pCur->serviceTime);
			printf("Total Time Waited: %d\n", pCur->totalTime);
			printf("\n");
			pCur = pCur->pNext;
		}
	}
	else
	{
		printf("There are no customers in the line.\n");
	}
}

/*
Function: int total_time(Queue pQ)
Date Created: February 10, 2016
Date Last Modified: February 10, 2016
Description: Adds up all of the service times of the previous customers.
Input Parameters: Queue pQ
Returns: None
Preconditions: A struct holding the lists pHead and pTail has to exist.
Postconditions: All of the service times are added up for the customers.
*/
int total_time(Queue pQ)
{
	QueueNode * pCur = pQ.pHead;
	int total = 0;

	while (pCur != NULL)
	{
		total += pCur->serviceTime;
		pCur = pCur->pNext;
	}

	return total;
}

/*
Functions: int isEmpty(Queue pQ)
Date Created: February 11, 2016
Date Last Modified: February 11, 2016
Description: Checks if the list is empty
Input Parameters: Queue pQ
Returns: 1 if the list is empty and 0 if list is empty
Preconditions: A struct that holds the pHeaad and pTail of the list has to exist.
Postconditions: Checks if the list is empty.
*/
int isEmpty(Queue pQ)
{
	int success = 0;

	if (pQ.pHead == NULL)
	{
		success = 1;
	}

	return success;
}

