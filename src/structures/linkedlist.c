#include "linkedlist.h"

/*
 * initializes an empty linked list
 */
linkedlist_t* newlinkedlist()
{
	linkedlist_t* ll = malloc(sizeof(linkedlist_t));
	(*ll).head = NULL;

	return ll;
}

/*
 * initializes a new node with a value
 */
node_t* newNode(int value)
{
	node_t* n = malloc(sizeof(node_t));

	(*n).data = value;
	(*n).next = NULL;

	return n;
}

void insert(linkedlist_t* ll, int position, int value)
{
	if((*ll).head == NULL)
	{
		append(ll, value);

		return;
	}

	node_t* current = (*ll).head;
	node_t* prev;

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

	node_t* newNextNode = current;
	node_t* insertNode = newNode(value);

	(*insertNode).next = newNextNode;
	(*prev).next = insertNode;
}

void deleteNode(linkedlist_t* ll, int position)
{
	if((*ll).head == NULL)
	{
		return;
	}

	if(position == 0)
	{
		(*ll).head = (*((*ll).head)).next;
	}

	node_t* current = (*ll).head;
	node_t* prev;

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

	node_t* newNextNode = (*current).next;
	(*prev).next = newNextNode;
}

/*
 * adds a node to the end of the linked list
 */
void append(linkedlist_t* ll, int value)
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
	node_t* current = (*ll).head;
	while((*current).next != NULL)
	{
		current = (*current).next;
	}

	node_t* retNode = NULL; 
	retNode = newNode(value);
	(*current).next = retNode;
}

/*
 * returns the data stored in a node
 */
int getData(node_t* n)
{
	return (*n).data;
}

/*
 * prints entire linked list into console
 */
void printAll(linkedlist_t* ll)
{
	/* if the linked list is empty, we can just skip
	 * to the end
	 */
	if((*ll).head != NULL)
	{
		/* loop through all of the nodes in the
		 * linked list and prints them
		 */
		node_t* current = (*ll).head;
		while(current != NULL)
		{
			printf("%d -> ", getData(current));
			current = (*current).next;
		}
	}
	printf("empty\n");
}

