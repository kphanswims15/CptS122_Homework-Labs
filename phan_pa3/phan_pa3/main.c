/********************************************************************************************************************************
* Programmer: Kimi Phan                                                                                                         *
*                                                                                                                               *
* Class: Cpts 122, Spring 2016, Lab Section: 05                                                                                 *
*                                                                                                                               *
* Programming Assignment: PA 3: Grocery Store Simulation                                                                        *
*                                                                                                                               *
* Date: February 8, 2016                                                                                                        *
*                                                                                                                               *
* Date Last Modified: February 11, 2016                                                                                         *
*                                                                                                                               *
* Description: One of your queues will represent the express lane and the other a normal lane. You will randomly generate       *
*		arrival times and service times of customers into each lane. The express lane has customers arrive every one to five    *
*		minutes, and customers arrive every three to eight minutes in the normal lane. Service times vary from one to five      *
*		minutes, and three to eight minutes, for express and normal lane customers, respectively. As customers arrive into      *
*		each line print out a message indicating in which line each customer arrives, along with the overall corresponding      *
*		arrival time and customer number. When customers have finished checking out, print out a message indicating which line  *
*		the customer was in, along the corresponding customer number and totalTime in the line. Allow for the simulation to run *
*		for n number of minutes, where n is inputted by the user.                                                               *     
*********************************************************************************************************************************/

#include "functions.h"

int main(void)
{
	run_app();

	return 0;
} 