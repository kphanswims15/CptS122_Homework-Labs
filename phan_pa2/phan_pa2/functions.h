/**************************************************************************
* Date Created: January 31, 2016                                          *
* Date Last Modified: February 6, 2016                                    *
* Description: Holds defines and standard libraries and function headers. *
***************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define _CRT_SECURE_NO_WARNINGS

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct length
{
	int minutes;
	int seconds;
}Length;

typedef struct record
{
	char artist[MAX];
	char title[MAX];
	char song[MAX];
	char genre[MAX];
	Length duration;
	int number_times_played;
	int rating;
}Record;

typedef struct node
{
	Record info;
	struct node *pPrev;
	struct node *pNext;
}Node;

void run_app(Node **pHead);
int menu(void);
FILE *open_file_read(void);
FILE *open_file_write(void);
Node *makeNode(Record info);
void display(Node *pHead);
void insertInOrder(Node **pHead, Record info);
void load(Node **pHead);
void store(Node *pHead);
void insert(Node **pHead);
int search_menu(void);
int edit_menu(void);
void print_one_record(Node *pHead);
void get_artist(char *temp);
void get_title(char *temp);
void get_song(char *temp);
void get_genre(char *temp);
void get_length(int *num, int *num2);
void get_number_times_played(int *num);
void get_rating(int *num);
Node * search_for_artist(Node *pHead, char *temp);
Node * search_for_title(Node *pHead, char *temp);
Node * search_for_song(Node *pHead, char *temp);
Node * search_for_genre(Node *pHead, char *temp);
Node * search_for_length(Node *pHead, int num, int num2);
Node * search_for_number_times_played(Node *pHead, int num);
Node * search_for_rating(Node *pHead, int num);
Node * run_search_menu( Node *pHead);
void edit(Node *pHead);
void rate(Node *pHead);
void delete_record(Node **pHead);
int sort_menu(void);
void sort_artist(Node *pHead);
void sort_title(Node *pHead);
void sort_song(Node *pHead);
void sort_genre(Node *pHead);
void sort_length(Node *pHead);
void sort_number_times_played(Node *pHead);
void sort_rating(Node *pHead);
void run_sort(int option, Node *pHead);

#endif