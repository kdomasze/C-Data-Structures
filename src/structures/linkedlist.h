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
 * frees a given linked list from memory
 */
void freeLinkedList(linkedlist_t* ll);

/*
 * initializes a new node with a value
 */
node_t* newNode(int value);

/*
 * frees a given node from memory
 */
void freeNode(node_t* node);

/*
 * inserts a node at the given position, moving the
 * element origionally in that position to position + 1
 *
 * by default, the function will append the created node to
 * theend of the linked list if the position exceeds the 
 * length of the linked list (with an empty list defaulting
 * with the insert as the first and only node)
 */
void insert(linkedlist_t* ll, int position, int value);

/*
 * deletes a node at the given position, moving the element in
 * position + 1 to position
 *
 * by default, if the position given is not valid for the list
 * (i.e. exceeds the length of the list), the function will
 * not modify the list
 */
void deleteNode(linkedlist_t* ll, int position);

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
