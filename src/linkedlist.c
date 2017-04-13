#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct linkedlist
{
	struct node* head;
};

/*
 * initializes an empty linked list
 */
struct linkedlist* newlinkedlist()
{
	struct linkedlist* ll = malloc(sizeof(struct linkedlist));
	(*ll).head = NULL;

	return ll;
}

/*
 * initializes a new node with a value
 */
struct node* newNode(int value)
{
	struct node* n = malloc(sizeof(struct node));

	(*n).data = value;
	(*n).next = NULL;

	return n;
}
/*
 * adds a node to the end of the linked list
 */
void append(struct linkedlist* ll, int value)
{
	// if the linked list is empty, we can just add
	// a new node right away
	if((*ll).head == NULL)
	{
		(*ll).head = newNode(value);

		return;
	}

	// otherwise, we need to find the end of the list
	// to append the node
	struct node* current = (*ll).head;
	while((*current).next != NULL)
	{
		current = (*current).next;
	}

	struct node* retNode = NULL; 
	retNode = newNode(value);
	(*current).next = retNode;
}

/*
 * returns the data stored in a node
 */
int getData(struct node* n)
{
	return (*n).data;
}

/*
 * prints entire linked list into console
 */
void printAll(struct linkedlist* ll)
{
	// if the linked list is empty, we can just skip
	// to the end
	if((*ll).head != NULL)
	{
		// loop through all of the nodes in the
		// linked list and prints them
		struct node* current = (*ll).head;
		while(current != NULL)
		{
			printf("%d -> ", getData(current));
			current = (*current).next;
		}
	}
	printf("empty\n");
}
int main()
{
	// quickly test functionality
	struct linkedlist* ll = newlinkedlist();
	
	append(ll, 1);
	append(ll, 2);
	append(ll, 3);
	append(ll, 4);	
	append(ll, 5);
	append(ll, 6);

	printAll(ll);

	return 0;
}
