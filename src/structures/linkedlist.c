#include "linkedlist.h"

linkedlist* newlinkedlist()
{
	linkedlist* ll = malloc(sizeof(linkedlist));
	(*ll).head = NULL;

	return ll;
}

void freeLinkedList(linkedlist* ll)
{
	node* current = (*ll).head;
	node* next;
	while(current != NULL)
	{
		next = (*current).next;
		freeNode(current);
		current = next;
	}

	free(ll);
}

node* newNode(int value)
{
	node* n = malloc(sizeof(node));

	(*n).data = value;
	(*n).next = NULL;

	return n;
}

void freeNode(node* node)
{
	free(node);
}

void insert(linkedlist* ll, int position, int value)
{
	if((*ll).head == NULL)
	{
		append(ll, value);

		return;
	}

	node* current = (*ll).head;
	node* prev;

	int i;

	for(i = 0; i < position; i++)
	{
		prev = current;
		current = (*current).next;
		if(current == NULL)
		{
			append(ll, value);

			return;
		}
	}

	node* newNextNode = current;
	node* insertNode = newNode(value);

	(*insertNode).next = newNextNode;
	(*prev).next = insertNode;
}

void deleteNode(linkedlist* ll, int position)
{
	if((*ll).head == NULL)
	{
		return;
	}

	node* current = (*ll).head;

	if(position == 0)
	{
		(*ll).head = (*((*ll).head)).next;
		freeNode(current);

		return;
	}

	node* prev;

	int i;

	for(i = 0; i < position; i++)
	{
		prev = current;
		current = (*current).next;
		
		if(current == NULL)
		{
			return;
		}
	}

	node* newNextNode = (*current).next;
	(*prev).next = newNextNode;

	freeNode(current);
}

void append(linkedlist* ll, int value)
{
	/* if the linked list is empty, we can just add
	 * a new node right away
	 */
	if((*ll).head == NULL)
	{
		(*ll).head = newNode(value);

		return;
	}

	/* otherwise, we need to find the end of the list
	 * to append the node
	 */
	node* current = (*ll).head;
	while((*current).next != NULL)
	{
		current = (*current).next;
	}

	node* retNode = NULL; 
	retNode = newNode(value);
	(*current).next = retNode;
}


int getData(node* n)
{
	return (*n).data;
}

void printAll(linkedlist* ll)
{
	/* if the linked list is empty, we can just skip
	 * to the end
	 */
	if((*ll).head != NULL)
	{
		/* loop through all of the nodes in the
		 * linked list and prints them
		 */
		node* current = (*ll).head;
		while(current != NULL)
		{
			printf("%d -> ", getData(current));
			current = (*current).next;
		}
	}
	printf("empty\n");
}

