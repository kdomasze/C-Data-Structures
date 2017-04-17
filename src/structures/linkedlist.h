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
} node;

typedef struct linkedlist
{
	struct node* head;
} linkedlist;


/*
 * initializes an empty linked list
 */
linkedlist* newlinkedlist();

/*
 * frees a given linked list from memory
 */
void freeLinkedList(linkedlist* ll);

/*
 * initializes a new node with a value
 */
node* newNode(int value);

/*
 * frees a given node from memory
 */
void freeNode(node* node);

/*
 * returns the length of a linked list
 */
int length(linkedlist* ll);

/*
 * inserts a node at the given position, moving the
 * element origionally in that position to position + 1
 *
 * by default, the function will append the created node to
 * the end of the linked list if the position exceeds the 
 * length of the linked list (with an empty list defaulting
 * with the insert as the first and only node)
 */
void insert(linkedlist* ll, int position, int value);

/*
 * deletes a node at the given position, moving the element in
 * position + 1 to position
 *
 * by default, if the position given is not valid for the list
 * (i.e. exceeds the length of the list), the function will
 * not modify the list
 */
void deleteNode(linkedlist* ll, int position);

/*
 * adds a node to the beginning of the linked list
 */
void push(linkedlist* ll, int value);

/*
 * adds a node to the end of the linked list
 */
void append(linkedlist* ll, int value);

/*
 * returns the data stored in a node
 */
int getData(node* n);

/*
 * returns a copy of the linked list
 */
linkedlist* copy(linkedlist* ll);

/*
 * prints entire linked list into console
 */
void printAll(linkedlist* ll);

#endif
