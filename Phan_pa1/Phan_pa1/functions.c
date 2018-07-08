/******************************************************************************
* Description: Defines all of the functions.                                  *
*                                                            
* Includes these functions: -void run_app(void)
							-void run_sorting_strings(void)
							-void sort_strings_ascending(int num_strings, char *pList_of_strings)
*/

#include "functions.h"

/*************************************************************
* Function: void run_app (void)                           *
* Date Created: January 15, 2016                            *
* Date Last Modified:                     *
* Description: Runs the program with all the functions in it.
* Input parameters: None.                                 *
* Returns: None.                                        *
* Preconditions: All of the functions need to be defined and created.
* Postconditions: Should run the whole program.          *
*************************************************************/
void run_app(void)
{
	run_sorting_strings();
}

/****************************************************************
 * Function: void run_sorting_strings(void)                     *
 * Date Created: January 15, 2016                               *
 * Date Last Modified:                                          * 
 * Description: Runs the sorting string function.               *
 * Input parameters: None.                                      *
 * Returns: None.                                               *
 * Preconditions: Sorting strings function needs to be created. *
 * Postconditions: Should run the whole program.                *
 ****************************************************************/
void run_sorting_strings(void)
{
	int count = 0;
	char *list[] = {"harry", "snape", "ron", "dumbledore", "lupin"};

	printf("List Before: ");
	for (count = 0; count < 5; count++)
	{
		printf("%s ", list[count]);
	}
	printf("\n\n");

	sort_strings_ascending(5, list);
	printf("List in ascending order: ");
	for (count = 0; count < 5; count++)
	{
		printf("%s ", list[count]);
	}
	printf("\n");
}

/************************************************************************************************
 * Function: void sort_strings_ascending(int num_strings, char *pList_of_strings)               *
 * Date Created: January 16, 2016                                                               *
 * Date Last Modified:                                                                          *
 * Description: Sorts strings in a list in ascending order.                                     *
 * Input parameters: None.                                                                      *
 * Returns: None.                                                                               *
 * Preconditions: The size of the list should be known and a list of strings should be created. *
 * Postconditions: List of strings should be ordered in ascending order.                        *
 ************************************************************************************************/
void sort_strings_ascending(char *ptr, int num_strings)
{
	
}