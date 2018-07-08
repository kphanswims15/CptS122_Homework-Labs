/****************************************************************************************************************************
* Programmer: Kimi Phan                                                                                                     *
*                                                                                                                           *
* Class: Cpts 122, Spring 2016, Lab Section: 05                                                                             *
*                                                                                                                           *
* Programming Assignment: PA2: Digital Music Manager & Doubly Linked List                                                   *
*                                                                                                                           *
* Date: January 31, 2016                                                                                                    *
*                                                                                                                           *
* Date Last Modified: February 6, 2016                                                                                      *
*                                                                                                                           *
* Description: Your DMM program must have a text-based interface which allows the user to select from a menu of options     *
*		including: load, store, display, insert, delete, edit, sort, rate, and exit. The “load” option reads records        *
*		from a file into a dynamic doubly linked list. The “store” command writes records, in a dynamic doubly linked       *
*		list, to a file. “Display” prints records, and its attributes to the screen. This command must print either         *
*		all records or a single record based on a search field. A search field may be any of the attributes belonging       *
*		to a record. If a search field matches multiple records, then print the first match to the screen. The “insert”     *
*		option collects information for each new song record and attributes from the user. The new song record must be      *
*		placed into the list based on a selected sort option. By default, songs are inserted into the list alphabetically   *
*		(‘a’ – ‘z’) according to artist. Other possible “sort” options include alphabetical ordering based on genre, or     *
*		increasing numeric value based on rating. “Delete” removes a record from the list. Deletion is based on song title. *
*		The “edit” option must allow the user to find a record in the list with any search field. The user may modify any   *
*		of the attributes in the record. The “rate” action must allow the user to assign a value of 1 – 5 to a song; 1 is   *
*		the lowest rating and 5 is the highest rating. Lastly, “exit” saves the most recent list to a file.                 *
*                                                                                                                           *
* Got Help From: Daylan and Lucy and http://geeksquiz.com/c-program-bubble-sort-linked-list/                                *
*****************************************************************************************************************************/

#include "functions.h"

int main(void)
{
	Node *pHead = NULL;

	run_app(&pHead);

	return 0;
}