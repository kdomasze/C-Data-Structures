#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node;
struct linkedlist;

typedef struct node
{
	int data;
	struct node* next;
} node_t;

typedef struct linkedlist
{
	struct node* head;
} linkedlist_t;


/*
 * initializes an empty linked list
 */
linkedlist_t* newlinkedlist();

/*
 * initializes a new node with a value
 */
node_t* newNode(int value);

/*
 * adds a node to the end of the linked list
 */
void append(linkedlist_t* ll, int value);

/*
 * returns the data stored in a node
 */
int getData(node_t* n);

/*
 * prints entire linked list into console
 */
void printAll(linkedlist_t* ll);

#endif
