#include "functions.h"

/*
* Function:
* Date Created:
* Date Last Modified:
* Description: 
* Input Parameters:
* Returns: 
* Preconditions: 
* Postconditions: 
*/

/******************************************************
* Function: void run_app(void)                        *
* Date Created: January 31, 2016                      *
* Date Last Modified: February 6, 2016                *
* Description: Runs the whole application.            *
* Input Parameters: None.                             *
* Returns: None                                       *
* Preconditions: Other functions need to be declared. *
* Postconditions: Runs the application.               *
*******************************************************/
void run_app(Node **pHead)
{
	int option = 0;
	int input = 0;
	Node *pCur = NULL;

	do
	{
		option = menu();
		system("cls");
		
		switch (option)
		{
		case 1: //load
			load(pHead);
			system("pause");
			system("cls");
			break;
		case 2: //store
			store(*pHead);
			system("pause");
			system("cls");
			break;
		case 3: //display
			display(*pHead);
			system("pause");
			system("cls");
			break;
		case 4: //insert
			insert(pHead);
			system("pause");
			system("cls");
			break;
		case 5: //delete
			delete_record(pHead);
			system("pause");
			system("cls");
			break;
		case 6: //edit
			pCur = run_search_menu(*pHead);
			edit(pCur);
			system("pause");
			system("cls");
			break;
		case 7: //sort
			input = sort_menu();
			run_sort(input, *pHead);
			system("pause");
			system("cls");
			break;
		case 8: //rate
			pCur = run_search_menu(*pHead);
			rate(pCur);
			system("pause");
			system("cls");
			break;
		case 9: //exit
			printf("Thank you for visiting the Digital Music Manager!\n");
			store(*pHead);
			system("pause");
			system("cls");
			break;
		default: printf("Invalid input.\n");
			system("pause");
			system("cls");
			break;
		}
	} while (option != 9);
}

/****************************************************************************
* Function: int menu(void)                                                  *
* Date Created: January 31, 2016                                            *
* Date Last Modified: January 31, 2016                                      *
* Description: Displays the menu to the user and gets an option from them.  *
* Input Parameters: None.                                                   *
* Returns: the option that is chosen by the user.                           *
* Preconditions: A varible is declared to hold the number that is returned. *
* Postconditions: Displayes the menu and gets the user input.               *
*****************************************************************************/
int menu(void)
{
	int option = 0;

	printf("Welcome to the Digital Music Manager!\n");
	printf("1. load\n");
	printf("2. store\n");
	printf("3. display\n");
	printf("4. insert\n");
	printf("5. delete\n");
	printf("6. edit\n");
	printf("7. sort\n");
	printf("8. rate\n");
	printf("9. exit\n\n");
	
	printf("Please choose an option: ");
	scanf("%d", &option);

	return option;
}

/**************************************************
* Function: FILE * open_file_read(void)           *
* Date Created: February 1, 2016                  *
* Date Last Modified: February 1, 2016            *
* Description: Opens up a text file in read mode. * 
* Input Parameters: None.                         *
* Returns: The infile.                            *
* Preconditions: A file has to be created.        *
* Postconditions: Opens the file successfully.    *
***************************************************/
FILE * open_file_read(void)
{
	FILE *infile = NULL;

	infile = fopen("songs.txt", "r");

	return infile;
}

/************************************************
* Function: FILE * open_file_write(void)        *
* Date Created: February 1, 2016                *
* Date Last Modified: February 1, 2016          *
* Description: Opens a text file in write mode. *
* Input Parameters: None.                       *
* Returns: The outfile                          *
* Preconditions: A file has to be created.      *
* Postconditions: Opens the file sucessfully.   *
*************************************************/
FILE * open_file_write(void)
{
	FILE *outfile = NULL;

	outfile = fopen("songs.txt", "w");

	return outfile;
}

/*****************************************************************************************
* Function: Node * makeNode(Record info)                                                 *
* Date Created: February 1, 2016                                                         *
* Date Last Modified: February 1, 2016                                                   *
* Description: Allocate engough memory for a record in order to put it in a linked list. *
* Input Parameters: Record info.                                                         *
* Returns: A Node  * type.                                                               *
* Preconditions: The record info needs to be obtained either by reading it from the file *
*		or inputed by the user.                                                          *
* Postconditions: Memory is allocated for the record info and a Node * type is return.   *
******************************************************************************************/
Node * makeNode(Record info)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->info = info;
		pMem->pPrev = NULL;
		pMem->pNext = NULL;
	}

	return pMem;
}

/***************************************************************
* Function: void display(Node *pHead)                          *
* Date Created: February 1, 2016                               *
* Date Last Modified: February  1, 2016                        *
* Description: Displays the list of records.                   *
* Input Parameters: The head of list of records. (Node *pHead) *
* Returns: None.                                               *
* Preconditions: There has to be a list of records that exist. *
* Postconditions: The list of records will by printed.         *
****************************************************************/
void display(Node * pHead)
{
	if (pHead != NULL)
	{
		while (pHead != NULL)
		{
			printf("Artist: %s", pHead->info.artist);
			printf("Title: %s", pHead->info.title);
			printf("Song: %s", pHead->info.song);
			printf("Genre: %s", pHead->info.genre);
			printf("Length: %d min %d sec\n", pHead->info.duration.minutes, pHead->info.duration.seconds);
			printf("Number of times played: %d\n", pHead->info.number_times_played);
			printf("Rating: %d/5\n", pHead->info.rating);
			printf("\n");
			pHead = pHead->pNext;
		}
	}
	else
	{
		printf("There are no records to display.\n");
	}
}

/**********************************************************************************************
* Function: void insertInOrder(Node **pHead, Record info)                                     *
* Date Created: February 1, 2016                                                              *
* Date Last Modified: February 2, 2016                                                        *
* Description: Inserts the records in order by artist.                                        *
* Input Parameters: The address of the head record of the list and the info for the record.   *
* Returns: None.                                                                              *
* Preconditions: A list of records have to exist and the makeNode function has to be created. *
* Postconditions: When a new record is created it inserts the record inorder.                 *
***********************************************************************************************/
void insertInOrder(Node ** pHead, Record info)
{
	Node *pMem = NULL, *pTemp = NULL, *pCur = NULL;

	pMem = makeNode(info);

	if (pMem != NULL)
	{
		pTemp = *pHead;

		//list is empty
		if (pTemp == NULL)
		{
			*pHead = pMem;
		}
		else
		{
			//goes through the list
			while ((pTemp != NULL) && (strcmp(pMem->info.artist, pTemp->info.artist) > 0))
			{
				pCur = pTemp;
				pTemp = pTemp->pNext;
			}
			
			if (pCur != NULL)
			{
				//inserts anywhere
				pCur->pNext = pMem;
				pMem->pPrev = pCur;
				pMem->pNext = pTemp;
			}
			else
			{
				//inserts at the beginning
				*pHead = pMem;
				pMem->pNext = pTemp;
				pTemp->pPrev = pMem;
			}
		}
	}
	
}

/*****************************************************************************************
* Function: void read_file(FILE * infile, struct record info)                            * 
* Date Created: February 1, 2016                                                         *
* Date Last Modified: February 1, 2016                                                   *                                  
* Description: Read information from an file and creates a node to put in a linked list. *
* Input Parameters: an infile and a struct with record info.                             *
* Returns: None.                                                                         *
* Preconditions: A struct has been created and a file is not empty.                      *
* Postconditions: Reads info from the file into a struct and puts it in a linked list.   *
******************************************************************************************/
void load(Node **pHead)
{
	FILE *infile = NULL;
	Record info = { 0 };
	char temp = '\0';

	infile = open_file_read();

	if (infile != NULL)
	{
		printf("The file \"songs.txt\" opened up successfully!\n");
		if (fgets(info.artist, MAX, infile) == NULL)
		{
			printf("You do not have any records in your file.\n");
			fclose(infile);
		}
		else
		{
			fclose(infile);
			infile = open_file_read();

			while (!feof(infile))
			{
				fgets(info.artist, MAX, infile);
				fgets(info.title, MAX, infile);
				fgets(info.song, MAX, infile);
				fgets(info.genre, MAX, infile);
				fscanf(infile, "%d", &info.duration.minutes);
				fscanf(infile, "%d", &info.duration.seconds);
				fscanf(infile, "%d", &info.number_times_played);
				fscanf(infile, "%d", &info.rating);
				fscanf(infile, "%c", &temp);

				insertInOrder(pHead, info);
			}

			printf("Your records have been successfully loaded!\n");
			fclose(infile);
		}
	}
}

/*************************************************************
* Function: void store(Node *pHead)                          *
* Date Created: February 2, 2016                             *
* Date Last Modified: February 3, 2016                       *
* Description: Uploads the list of records to a file.        *
* Input Parameters: The head of the list of records.         *
* Returns: None.                                             *
* Preconditions: A list of records has to exist.             *
* Postconditions: The list of records is uploaded to a file. *
**************************************************************/
void store(Node * pHead)
{
	FILE *outfile = NULL;

	outfile = open_file_write();

		if (pHead != NULL)
		{
			while (pHead != NULL)
			{
				fprintf(outfile, "%s", pHead->info.artist);
				fprintf(outfile, "%s", pHead->info.title);
				fprintf(outfile, "%s", pHead->info.song);
				fprintf(outfile, "%s", pHead->info.genre);
				fprintf(outfile, "%d ", pHead->info.duration.minutes);
				fprintf(outfile, "%d\n", pHead->info.duration.seconds);
				fprintf(outfile, "%d\n", pHead->info.number_times_played);
				fprintf(outfile, "%d", pHead->info.rating);
				
				if (pHead->pNext != NULL)
				{
					fprintf(outfile, "\n");
				}

				pHead = pHead->pNext;
			}
			printf("You records are successfully loaded into \"songs.txt\"!\n");
			fclose(outfile);
		}
		else
		{
			printf("There is nothing to store.\n");
			fclose(outfile);
		}
}

/*************************************************************************************************
* Function: void insert(Node **pHead)                                                            *
* Date Created: February 2, 2016                                                                 *
* Date Last Modified: February 2, 2016                                                           *
* Description: Get info from the user to create a new record and inserts it in order.            *
* Input Parameters: The address of the first record.                                             *
* Returns: None.                                                                                 *
* Preconditions: The makeNode function has to exist and the insertInOrder function has to exist. *
* Postconditions: Inserts the new record in the existing list.                                   *
**************************************************************************************************/
void insert(Node ** pHead)
{
	Record info = { 0 };

	getchar();
	printf("Artist: ");
	fgets(info.artist, MAX, stdin);
	printf("Title: ");
	fgets(info.title, MAX, stdin);
	printf("Song: ");
	fgets(info.song, MAX, stdin);
	printf("Genre: ");
	fgets(info.genre, MAX, stdin);
	printf("Length (minutes and seconds): ");
	scanf("%d %d", &info.duration.minutes, &info.duration.seconds);
	printf("Number of Times played: ");
	scanf("%d", &info.number_times_played);
	printf("Rate (rating is out of 5): ");
	scanf("%d", &info.rating);

	insertInOrder(pHead, info);
}

/***************************************************************************************
* Function: int search_menu(void)                                                      *
* Date Created: February 3, 2016                                                       *
* Date Last Modified: February 3, 2016                                                 *
* Description: Displays the menu for the user to choose on how to search for a record. *
* Input Parameters: None.                                                              *
* Returns: The option chosen by the user.                                              *
* Preconditions: None.                                                                 *
* Postconditions: The option chosen by the user is returned.                           *
****************************************************************************************/
int search_menu(void)
{
	int option = 0;

	printf("Search by: \n");
	printf("1. Artist\n");
	printf("2. Title\n");
	printf("3. Song\n");
	printf("4. Genre\n");
	printf("5. Length\n");
	printf("6. Number of times played\n");
	printf("7. Rating\n");
	printf("8. Exit\n\n");

	printf("Please choose an option: ");
	scanf("%d", &option);

	return option;
}

/**************************************************************************************
* Function: int edit_menu(void)                                                       *
* Date Created: February 3, 2016                                                      *
* Date Last Modified: February 3, 2016                                                *
* Description: Displays a menu so the user can choose what field they want to change. *
* Input Parameters: None.                                                             *
* Returns: The option the user choses.                                                *
* Preconditions: None.                                                                *
* Postconditions: The option that the user choses is returned.                        *
***************************************************************************************/
int edit_menu(void)
{
	int option = 0;

	printf("Edit: \n");
	printf("1. Artist\n");
	printf("2. Title\n");
	printf("3. Song\n");
	printf("4. Genre\n");
	printf("5. Length\n");
	printf("6. Number of times played\n");
	printf("7. Rating\n");
	printf("8. Whole record\n\n");

	printf("Please choose an option: ");
	scanf("%d", &option);

	return option;
}

/**********************************************************************************************
* Function: void print_one_record(Node * pHead)                                               *
* Date Created: February 3, 2016                                                              *
* Date Last Modified: February 3, 2016                                                        *
* Description: Prints one record. Used when a match is found in a search.                     *
* Input Parameters: The record you want to insert.                                            *
* Returns: None.                                                                              *
* Preconditions: The record you want to search for is found and search functions are created. *
* Postconditions: The record is displayed.                                                    *
***********************************************************************************************/
void print_one_record(Node * pHead)
{
	printf("Artist: %s", pHead->info.artist);
	printf("Title: %s", pHead->info.title);
	printf("Song: %s", pHead->info.song);
	printf("Genre: %s", pHead->info.genre);
	printf("Lenght: %d min %d sec\n", pHead->info.duration.minutes, pHead->info.duration.seconds);
	printf("Number of times played: %d\n", pHead->info.number_times_played);
	printf("Rating: %d/5\n\n", pHead->info.rating);
}

/*********************************************************************************************
* Function: void get_artist(char *temp)                                                      *
* Date Created: February 3, 2016                                                             *
* Date Last Modified: February 3, 2016                                                       *
* Description: Gets an artist from the user. Used when you want to search or edit something. *
* Input Parameters: An empty char array (temp).                                              *
* Returns: None                                                                              *
* Preconditions: A empty char array has to exist.                                            *
* Postconditions: Gets the artist from the user.                                             *
**********************************************************************************************/
void get_artist(char * temp)
{
	getchar();
	printf("Artist: ");
	fgets(temp, MAX, stdin);
}

/*******************************************************************************************
* Function: void get_title(char * temp)                                                    *
* Date Created: February 3, 2016                                                           *
* Date Last Modified: February 3, 2016                                                     *
* Description: Gets a title from the user. Used when you want to search or edit this field *
* Input Parameters: An empty char array (temp).                                            *
* Returns: The user input.                                                                 *
* Preconditions: A empty char array has to exist.                                          *
* Postconditions: Gets the title from the user.                                            *
********************************************************************************************/
void get_title(char * temp)
{
	getchar();
	printf("Title: ");
	fgets(temp, MAX, stdin);
}

/******************************************************************************************
* Function: void get_song(char * temp)                                                    *
* Date Created: February 3, 2016                                                          *
* Date Last Modified: February 3, 2016                                                    *
* Description: Gets a song from the user. Used when you want to search or edit this field *
* Input Parameters: An empty char array (temp).                                           *
* Returns: User input                                                                     *
* Preconditions: A empty char array has to exist.                                         *
* Postconditions: Gets the song from the user.                                            *
*******************************************************************************************/
void get_song(char * temp)
{
	getchar();
	printf("Song: ");
	fgets(temp, MAX, stdin);
}

/*******************************************************************************************
* Function: void get_genre(char * temp)                                                    *
* Date Created: February 3, 2016                                                           *
* Date Last Modified: February 3, 2016                                                     *
* Description: Gets a genre from the user. Used when you want to search or edit this field *
* Input Parameters: An empty char array (temp).                                            *
* Returns: User input                                                                      *
* Preconditions: A empty char array has to exist.                                          *
* Postconditions: Gets the genre from the user.                                            *
********************************************************************************************/
void get_genre(char * temp)
{
	getchar();
	printf("Genre: ");
	fgets(temp, MAX, stdin);
}

/********************************************************************************************
* Function: void get_length(int *num, int *num2)                                            *
* Date Created: February 3, 2016                                                            *
* Date Last Modified: February 3, 2016                                                      *
* Description: Gets a length from the user. Used when you want to search or edit this field *
* Input Parameters: Two empty numbers.                                                      *
* Returns: User input                                                                       *
* Preconditions: Two empty numbers has to exist.                                            *
* Postconditions: Gets the length from the user.                                            *
*********************************************************************************************/
void get_length(int * num, int * num2)
{
	printf("Length (minutes and seconds): ");
	scanf("%d %d", num, num2);
}

/************************************************************************************************************
* Function: void get_number_times_played(int num)                                                           *
* Date Created: February 3, 2016                                                                            *
* Date Last Modified: February 3, 2016                                                                      *
* Description: Gets a number of times played from the user. Used when you want to search or edit this field *
* Input Parameters: An empty number.                                                                        *
* Returns: User input                                                                                       *
* Preconditions: A empty number has to exist.                                                               *
* Postconditions: Gets the number of times played from the user.                                            *
*************************************************************************************************************/
void get_number_times_played(int * num)
{
	printf("Number of times played: ");
	scanf("%d", num);
}

/**********************************************************************************************
* Function: void get_rating(char * temp)                                                      *
* Date Created: February 4, 2016                                                              *
* Date Last Modified: February 4, 2016                                                        *
* Description: Gets the rating from the user. Used when you want to search or edit this field *
* Input Parameters: An empty number.                                                          *
* Returns: User input                                                                         *
* Preconditions: A empty number has to exist.                                                 *
* Postconditions: Gets the rating from the user.                                              *
***********************************************************************************************/
void get_rating(int * num)
{
	printf("Rate (rating is out of 5): ");
	scanf("%d", num);
}

/**************************************************************************************************************
* Function: search_for_artist(Node *pHead, char *temp)                                                        *
* Date Created: February 3, 2016                                                                              *
* Date Last Modified: February 3, 2016                                                                        *
* Description: Searches for the artist based of the user input and prints out the record if a match is found. *
* Input Parameters: The head of the list of records and the user input.                                       *
* Returns: A Node * type.                                                                                     *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record   *
*		function has to exist.                                                                                *
* Postconditions: An match is found or not.                                                                   *
***************************************************************************************************************/
Node * search_for_artist(Node * pHead, char * temp)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL && strcmp(pCur->info.artist, temp) != 0)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n"); 
			print_one_record(pCur);
		}
	} 
	return pCur;
}

/**************************************************************************************************************
* Function: search_for_title(Node *pHead, char *temp)                                                         *
* Date Created: February 4, 2016                                                                              *
* Date Last Modified: February 4, 2016                                                                        *
* Description: Searches for the title based of the user input and prints out the record if a match is found.  *
* Input Parameters: The head of the list of records and the user input.                                       *
* Returns: A Node * type.                                                                                     *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record   *
*		function has to exist.                                                                                *
* Postconditions: An match is found or not.                                                                   *
***************************************************************************************************************/
Node * search_for_title(Node * pHead, char * temp)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL && strcmp(pCur->info.title, temp) != 0)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n");
			print_one_record(pCur);
		}
	}
	return pCur;
}

/************************************************************************************************************
* Function: search_for_song(Node *pHead, char *temp)                                                        *
* Date Created: February 4, 2016                                                                            *
* Date Last Modified: February 4, 2016                                                                      *
* Description: Searches for the song based of the user input and prints out the record if a match is found. *
* Input Parameters: The head of the list of records and the user input.                                     *
* Returns: A Node * type.                                                                                   *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record *
*		function has to exist.                                                                              *
* Postconditions: An match is found or not.                                                                 *
*************************************************************************************************************/
Node * search_for_song(Node * pHead, char * temp)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL && strcmp(pCur->info.song, temp) != 0)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n");
			print_one_record(pCur);
		}
	}
	return pCur;
}

/*************************************************************************************************************
* Function: search_for_genre(Node *pHead, char *temp)                                                        *
* Date Created: February 4, 2016                                                                             *
* Date Last Modified: February 4, 2016                                                                       *
* Description: Searches for the genre based of the user input and prints out the record if a match is found. *
* Input Parameters: The head of the list of records and the user input.                                      *
* Returns: A Node * type.                                                                                    *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record  *
*		function has to exist.                                                                               *
* Postconditions: An match is found or not.                                                                  *
**************************************************************************************************************/
Node * search_for_genre(Node * pHead, char * temp)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL && strcmp(pCur->info.genre, temp) != 0)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n");
			print_one_record(pCur);
		}
	}
	return pCur;
}
 
/**************************************************************************************************************
* Function: search_for_length(Node *pHead, int num, int num2)                                                 *
* Date Created: February 4, 2016                                                                              *
* Date Last Modified: February 4, 2016                                                                        *
* Description: Searches for the length based of the user input and prints out the record if a match is found. *
* Input Parameters: The head of the list of records and the user input.                                       *
* Returns: A Node * type.                                                                                     *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record   *
*		function has to exist.                                                                                *
* Postconditions: An match is found or not.                                                                   *
***************************************************************************************************************/
Node * search_for_length(Node * pHead, int num, int num2)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL && pCur->info.duration.minutes != num && pCur->info.duration.seconds != num2)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n");
			print_one_record(pCur);
		}
	}
	return pCur;
}

/**************************************************************************************************************
* Function: search_for_number_times_played(Node *pHead, int num)                                              *
* Date Created: February 4, 2016                                                                              *
* Date Last Modified: February 4, 2016                                                                        *
* Description: Searches for the number of times played based of the user input and prints out the record if a *
*		match is found.                                                                                       *
* Input Parameters: The head of the list of records and the user input.                                       *
* Returns: A Node * type.                                                                                     *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record   *
*		function has to exist.                                                                                *
* Postconditions: An match is found or not.                                                                   *
***************************************************************************************************************/
Node * search_for_number_times_played(Node * pHead, int num)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL &&  pCur->info.number_times_played != num)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n");
			print_one_record(pCur);
		}
	}
	return pCur;
}

/**************************************************************************************************************
* Function: search_for_rating(Node *pHead, int num)                                                           *
* Date Created: February 4, 2016                                                                              *
* Date Last Modified: February 4, 2016                                                                        *
* Description: Searches for the rating based of the user input and prints out the record if a match is found. *
* Input Parameters: The head of the list of records and the user input.                                       *
* Returns: A Node * type.                                                                                     *
* Preconditions: A user had inputed what they wanted to search and a list has to exist and print_one_record   *
*		function has to exist.                                                                                *
* Postconditions: An match is found or not.                                                                   *
***************************************************************************************************************/
Node * search_for_rating(Node * pHead, int num)
{
	Node *pCur = NULL;

	pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL && pCur->info.rating != num)
		{
			pCur = pCur->pNext;
		}

		if (pCur != NULL)
		{
			printf("Match found!\n");
			print_one_record(pCur);
		}
	}
	return pCur;
}

/************************************************************************************************************
* Function: Node * run_search_menu(Node *pHead)                                                             *
* Date Created: February 4, 2016                                                                            *
* Date Last Modified: February 5, 2016                                                                      *
* Description: Asks the user what field they want to search and it runs the search for that field.          *
* Input Parameters: The head of the list of records.                                                        *
* Returns: Node * type.                                                                                     *
* Preconditions: To get the info for each field has to exist, the search function for all of the fields has *
* 		to exist and the search menu has to exist.                                                          *
* Postconditions: Searchs for the record by on the field.                                                   *
*************************************************************************************************************/         
Node * run_search_menu(Node * pHead)
{
	char temp[MAX] = { '\0' };
	Node *pCur = NULL;
	int option = 0;
	int tNum = 0, tNum2 = 0;

	do
	{
		option = search_menu();
		system("cls");

		switch (option)
		{
		case 1://artist
			get_artist(temp);
			pCur = search_for_artist(pHead, temp);
			return pCur;
			break;
		case 2://title
			get_title(temp);
			pCur = search_for_title(pHead, temp);
			return pCur;
			break;
		case 3://song
			get_song(temp);
			pCur = search_for_song(pHead, temp);
			return pCur;
			break;
		case 4://genre
			get_genre(temp);
			pCur = search_for_genre(pHead, temp);
			return pCur;
			break;
		case 5://length
			get_length(&tNum, &tNum2);
			pCur = search_for_length(pHead, tNum, tNum2);
			return pCur;
			break;
		case 6://number of times played
			get_number_times_played(&tNum);
			pCur = search_for_number_times_played(pHead, tNum);
			return pCur;
			break;
		case 7://rating
			get_rating(&tNum2);
			pCur = search_for_rating(pHead, tNum);
			return pCur;
			break;
		case 8://exit;
		default: printf("Invalid input.\n");
			system("pause");
			system("cls");
			break;
		}
	} while (option != 8);

}

/*********************************************************
* Function: void edit(Node *pHead)                       *
* Date Created: February 3, 2016                         *
* Date Last Modified: February 4, 2016                   *
* Description: Allows the user to edit the record.       *
* Input Parameters: The record you want to edit.         *
* Returns: None.                                         *
* Preconditions: The record you wanted to edit is found. *
* Postconditions: The record it edited.                  *
**********************************************************/
void edit(Node * pHead)
{
	char input = '\0';
	int option = 0;
	char temp[MAX] = { '\0' };
	int tNum = 0, tNum2 = 0;

	if (pHead != NULL)
	{
		printf("Are you sure you want to edit this record? (y/n) ");
		scanf(" %c", &input);
		system("cls");

		if (input == 'y')
		{
			do
			{
				option = edit_menu();
				system("cls");

				switch (option)
				{
				case 1://artist
					get_artist(temp);
					strcpy(pHead->info.artist, temp);
					system("cls");
					printf("The record has been changed.\n");
					break;
				case 2://title
					get_title(temp);
					strcpy(pHead->info.title, temp);
					system("cls");
					printf("The record has been changed.\n");
					break;
				case 3://song
					get_song(temp);
					strcpy(pHead->info.song, temp);
					printf("The record has been changed.\n");
					system("cls");
					break;
				case 4://genre
					get_genre(temp);
					strcpy(pHead->info.genre, temp);
					system("cls");
					printf("The record has been changed.\n");
					break;
				case 5://length
					get_length(&tNum, &tNum2);
					pHead->info.duration.minutes = tNum;
					pHead->info.duration.seconds = tNum2;
					system("cls");
					printf("The record has been changed.\n");
					break;
				case 6://number of times played
					get_number_times_played(&tNum);
					pHead->info.number_times_played = tNum;
					system("cls");
					printf("The record has been changed.\n");
					break;
				case 7://rating
					get_rating(&tNum);
					pHead->info.rating = tNum;
					system("cls");
					printf("The record has been changed.\n");
					break;
				case 8://whole record
					getchar();
					printf("Artist: ");
					fgets(temp, MAX, stdin);
					strcpy(pHead->info.artist, temp);
					printf("Title: ");
					fgets(temp, MAX, stdin);
					strcpy(pHead->info.title, temp);
					printf("Song: ");
					fgets(temp, MAX, stdin);
					strcpy(pHead->info.song, temp);
					printf("Genre: ");
					fgets(temp, MAX, stdin);
					strcpy(pHead->info.genre, temp);
					get_length(&tNum, &tNum2);
					pHead->info.duration.minutes = tNum;
					pHead->info.duration.seconds = tNum2;
					get_number_times_played(&tNum);
					pHead->info.number_times_played = tNum;
					get_rating(&tNum);
					pHead->info.rating = tNum;
					system("cls");
					printf("The record has been changed.\n");
					break;
				default: printf("Invalid input.\n");
					system("pause");
					system("cls");
					break;
				}
			} while (option < 1 || option > 8);
		}
		else
		{
			printf("Nothing changed.\n");
		}
	}
	else
	{
		printf("Match was not found.\n");
	}
}

/*******************************************************
* Function: void rate(Node *pHead)                     *
* Date Created: February 4, 2016                       *
* Date Last Modified: February 4, 2016                 *
* Description: Allows the user to rated the record.    *
* Input Parameters: The record you want to rate.       *
* Returns: None.                                       *
* Preconditions: The record you want to rate is found. *
* Postconditions: The record is rated.                 *
********************************************************/
void rate(Node * pHead)
{
	char input = '\0';
	int tNum = 0;

	if (pHead != NULL)
	{
		printf("Are you sure you want to rate this record? (y/n) ");
		scanf(" %c", &input);
		system("cls");

		if (input == 'y')
		{
			get_rating(&tNum);
			pHead->info.rating = tNum;
			system("cls");
			printf("You have rated the record.\n");
		}
	}
	else
	{
		printf("Match was not found.\n");
	}
}

/****************************************************
* Function: void delete_record(Node **pHead)        *
* Date Created: February 5, 2016                    *
* Date Last Modified: February 6, 2016              *
* Description: Deletes the record from the list.    * 
* Input Parameters: The address of the head record. * 
* Returns: None                                     *
* Preconditions: The list cannot be empty.          *
* Postcondtions: A record is deleted from the list. *
*****************************************************/
void delete_record(Node ** pHead)
{
	char input = '\0';
	int option = 0, tNum = 0, tNum2 = 0;
	Node * pCur = *pHead, *pPrev = NULL, *pNext = NULL;
	char temp[MAX] = { '\0' };

	if (*pHead != NULL)
	{
		option = search_menu();
		system("cls");

		switch (option)
		{
		case 1://artist
			get_artist(temp);
			while (pCur != NULL && strcmp(pCur->info.artist, temp) != 0)
			{			
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 2://title
			get_title(temp);
			while (pCur != NULL && strcmp(pCur->info.title, temp) != 0)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 3://song
			get_song(temp);
			while (pCur != NULL && strcmp(pCur->info.song, temp) != 0)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 4://genre
			get_genre(temp);
			while (pCur != NULL && strcmp(pCur->info.genre, temp) != 0)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 5://length
			get_length(&tNum, &tNum2);
			while (pCur != NULL && pCur->info.duration.minutes != tNum && pCur->info.duration.seconds != tNum2)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 6://number of times played
			get_number_times_played(&tNum);
			while (pCur != NULL && pCur->info.number_times_played != tNum)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 7://rating
			get_rating(&tNum);
			while (pCur != NULL && pCur->info.rating != tNum)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			break;
		case 8://exit
			break;
		default: printf("Invalid input.\n");
			system("pause");
			system("cls");
			break;
		}

		if (pCur != NULL)
		{
			print_one_record(pCur);
			printf("Are you sure you want delete this record? (y/n) ");
			scanf(" %c", &input);
			system("cls");

			if (input == 'y')
			{
				if (pPrev != NULL && pCur->pNext != NULL)
				{
					pPrev->pNext = pCur->pNext;
					pNext = pCur->pNext;
					pNext->pPrev = pCur->pPrev;
					free(pCur);
				}
				else if (pPrev != NULL && pCur->pNext == NULL)
				{
					pPrev->pNext = NULL;
					free(pCur);
				}
				else if (pPrev == NULL && pCur->pNext != NULL)
				{
					pCur->pNext->pPrev = NULL;
					*pHead = pCur->pNext;
					free(pCur);
				}
				else
				{
					free(pCur);
					*pHead = NULL;
				}
				printf("Your record was deleted.\n");
			}
			else
			{
				printf("Your record was not deleted.\n");
			}
		}
		else
		{
			printf("Match was not found.\n");
		}
	}
	else
	{
		printf("There is nothing to delete.\n");
	}
}

/*****************************************************************************************************
* Function: int sort_menu(void)                                                                      *
* Date Created: February 6, 2016                                                                     *
* Date Last Modified: February 6, 2016                                                               *
* Description: Prints a menu to the user based so they can choose what field they want to search by. *
* Input Parameters: None.                                                                            *
* Returns: option chosen by the user.                                                                *
* Precondtions: None.                                                                                *
* Postconditions: The option of the user is chosen.                                                  * 
******************************************************************************************************/
int sort_menu(void)
{
	int option = 0;

	printf("Sort by:\n");
	printf("1. Artist\n");
	printf("2. Title\n");
	printf("3. Song\n");
	printf("4. Genre\n");
	printf("5. Length\n");
	printf("6. Number of times played\n");
	printf("7. Rating\n");
	printf("8. Exit\n\n");

	printf("Please choose an option: ");
	scanf("%d", &option);

	return option;
}

/************************************************************
* Function: void sort_artist(Node *pHead)                   *
* Date Created: February 6, 2016                            *
* Date Last Modified: February 6, 2016                      *
* Description: Sorts the list by artist in ascending order. *
* Input Paramters: The first record of the list.            *
* Returns: None                                             *
* Preconditions: A list has to exist.                       *
* Postconditions: The list will be in ascending order.      *
*************************************************************/
void sort_artist(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (strcmp(pCur->info.artist, pCur->pNext->info.artist) > 0)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/************************************************************
* Function: void sort_title(Node *pHead)                    *
* Date Created: February 6, 2016                            *
* Date Last Modified: February 6, 2016                      *
* Description: Sorts the list by title in ascending order.  *
* Input Paramters: The first record of the list.            *
* Returns: None                                             *
* Preconditions: A list has to exist.                       *
* Postconditions: The list will be in ascending order.      *
*************************************************************/
void sort_title(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (strcmp(pCur->info.title, pCur->pNext->info.title) > 0)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/**********************************************************
* Function: void sort_song(Node *pHead)                   *
* Date Created: February 6, 2016                          *
* Date Last Modified: February 6, 2016                    *
* Description: Sorts the list by song in ascending order. *
* Input Paramters: The first record of the list.          *
* Returns: None                                           *
* Preconditions: A list has to exist.                     *
* Postconditions: The list will be in ascending order.    *
***********************************************************/
void sort_song(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (strcmp(pCur->info.song, pCur->pNext->info.song) > 0)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/************************************************************
* Function: void sort_genre(Node *pHead)                    *
* Date Created: February 6, 2016                            *
* Date Last Modified: February 6, 2016                      *
* Description: Sorts the list by genre in ascending order.  *
* Input Paramters: The first record of the list.            *
* Returns: None                                             *
* Preconditions: A list has to exist.                       *
* Postconditions: The list will be in ascending order.      *
*************************************************************/
void sort_genre(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (strcmp(pCur->info.genre, pCur->pNext->info.genre) > 0)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/************************************************************
* Function: void sort_length(Node *pHead)                   *
* Date Created: February 6, 2016                            *
* Date Last Modified: February 6, 2016                      *
* Description: Sorts the list by length in ascending order. *
* Input Paramters: The first record of the list.            *
* Returns: None                                             *
* Preconditions: A list has to exist.                       *
* Postconditions: The list will be in ascending order.      *
*************************************************************/
void sort_length(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (pCur->info.duration.minutes > pCur->pNext->info.duration.minutes)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				else if (pCur->info.duration.seconds > pCur->pNext->info.duration.seconds)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/****************************************************************************
* Function: void sort_number_times_played(Node *pHead)                      *
* Date Created: February 6, 2016                                            * 
* Date Last Modified: February 6, 2016                                      *
* Description: Sorts the list by number of times played in ascending order. *
* Input Paramters: The first record of the list.                            *
* Returns: None                                                             *
* Preconditions: A list has to exist.                                       *
* Postconditions: The list will be in ascending order.                      *
*****************************************************************************/
void sort_number_times_played(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (pCur->info.number_times_played > pCur->pNext->info.number_times_played)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/************************************************************
* Function: void sort_rating(Node *pHead)                   *
* Date Created: February 6, 2016                            *
* Date Last Modified: February 6, 2016                      *
* Description: Sorts the list by rating in ascending order. *
* Input Paramters: The first record of the list.            *
* Returns: None                                             *
* Preconditions: A list has to exist.                       *
* Postconditions: The list will be in ascending order.      *
*************************************************************/
void sort_rating(Node * pHead)
{
	Node *pCur = NULL, *pPrev = NULL;
	Record temp;
	int swapped = 0;

	if (pHead != NULL)
	{
		do
		{
			swapped = 0;
			pCur = pHead;

			while (pCur->pNext != pPrev)
			{
				if (pCur->info.rating > pCur->pNext->info.rating)
				{
					temp = pCur->info;
					pCur->info = pCur->pNext->info;
					pCur->pNext->info = temp;
					swapped = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;
		} while (swapped);
	}
	else
	{
		printf("There is nothing to sort");
	}
}

/****************************************************************************************************
* Function: void run_sort(int option, Node *pHead)                                                  *
* Date Created: February 6, 2016                                                                    *
* Date Last Modified: February 6, 2016                                                              *
* Description: An has been chosen by the user and it sorts the list by on the field hat was chosen. *
* Input Parameters: The first recond in the list ans the option chosen by the user.                 *
* Returns: None.                                                                                    *
* Precondtions: The list is not empty and the user had chosen what they want to sort by.            *
* Postconditions: The list should be sorted based on what the user wanted to sort by.               *
*****************************************************************************************************/
void run_sort(int option, Node *pHead)
{
	switch (option)
	{
	case 1://artist
		sort_artist(pHead);
		break;
	case 2://title
		sort_title(pHead);
		break;
	case 3://song
		sort_song(pHead);
		break;
	case 4://genre
		sort_genre(pHead);
		break;
	case 5://length
		sort_length(pHead);
		break;
	case 6://number times played
		sort_number_times_played(pHead);
		break;
	case 7://rating
		sort_rating(pHead);
		break;
	case 8://exit 
		break;
	default: printf("Invalid input.\n");
		system("pause");
		system("cls");
		break;
	}

	printf("Your songs have been successfully sorted.\n");
}
	

