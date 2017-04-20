#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList* kd_linked_list_new()
{
	LinkedList* linked_list = malloc(sizeof(LinkedList));
	(*linked_list).head = NULL;

	return linked_list;
}

void kd_linked_list_free(LinkedList* linked_list)
{
	Node* current = (*linked_list).head;
	Node* next;
	
	while(current != NULL)
	{
		next = (*current).next;
		kd_linked_list_node_free(current);
		current = next;
	}

	free(linked_list);
}

Node* kd_linked_list_node_new(int value)
{
	Node* n = malloc(sizeof(Node));

	(*n).data = value;
	(*n).next = NULL;

	return n;
}

void kd_linked_list_node_free(Node* node)
{
	free(node);
}

int kd_linked_list_length(LinkedList* linked_list)
{
	int count = 0;

	Node* current = (*linked_list).head;
	while(current != NULL)
	{
		count++;

		current = (*current).next;
	}

	return count;
}

void kd_linked_list_insert(LinkedList* linked_list, int position, int value)
{
	if((*linked_list).head == NULL)
	{
		kd_linked_list_append(linked_list, value);

		return;
	}

	Node* current = (*linked_list).head;
	Node* prev;

	int i;

	for(i = 0; i < position; i++)
	{
		prev = current;
		current = (*current).next;
		if(current == NULL)
		{
			kd_linked_list_append(linked_list, value);

			return;
		}
	}

	Node* new_next_node = current;
	Node* insert_node = kd_linked_list_node_new(value);

	(*insert_node).next = new_next_node;
	(*prev).next = insert_node;
}

void kd_linked_list_node_delete(LinkedList* linked_list, int position)
{
	if((*linked_list).head == NULL)
	{
		return;
	}

	Node* current = (*linked_list).head;

	if(position == 0)
	{
		(*linked_list).head = (*((*linked_list).head)).next;
		kd_linked_list_node_free(current);

		return;
	}

	Node* prev;

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

	Node* node_new = (*current).next;
	(*prev).next = node_new;

	kd_linked_list_node_free(current);
}

void kd_linked_list_push(LinkedList* linked_list, int value)
{
	/*
	 * if the linked list is empty, we can just add
	 * a new node right away
	 */
	if((*linked_list).head == NULL)
	{
		(*linked_list).head = kd_linked_list_node_new(value);

		return;
	}
	
	/* 
	 * otherwise, we just insert at the start
	 */
	Node* node_new = kd_linked_list_node_new(value);
	(*node_new).next = (*linked_list).head;
	(*linked_list).head = node_new;
}

void kd_linked_list_append(LinkedList* linked_list, int value)
{
	/* 
	 * if the linked list is empty, we can just add
	 * a new node right away
	 */
	if((*linked_list).head == NULL)
	{
		(*linked_list).head = kd_linked_list_node_new(value);

		return;
	}

	/* 
	 * otherwise, we need to find the end of the list
	 * to kd_linked_list_append the node
	 */
	Node* current = (*linked_list).head;
	while((*current).next != NULL)
	{
		current = (*current).next;
	}

	Node* node_new = NULL; 
	node_new = kd_linked_list_node_new(value);
	(*current).next = node_new;
}


int _kd_linked_list_node_get(Node* node)
{
	return (*node).data;
}

int kd_linked_list_get(LinkedList* linked_list, int position)
{
	Node* current = (*linked_list).head;
	int i;
	for(i = 0; i < position; i++)
	{
		current = (*current).next;
	}

	return _kd_linked_list_node_get(current);
}

LinkedList* kd_linked_list_copy(LinkedList* linked_list)
{
	LinkedList* linked_list_new = kd_linked_list_new();

	Node* current = (*linked_list).head;
	while(current != NULL)
	{
		kd_linked_list_append(linked_list_new, _kd_linked_list_node_get(current));
		current = (*current).next;
	}

	return linked_list_new;
}
