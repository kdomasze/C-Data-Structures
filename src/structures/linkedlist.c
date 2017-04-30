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
	LL_Node* current = (*linked_list).head;
	LL_Node* next;
	
	while(current != NULL)
	{
		next = (*current).next;
		kd_linked_list_node_free(current);
		current = next;
	}

	free(linked_list);
}

LL_Node* kd_linked_list_node_new(int value)
{
	LL_Node* n = malloc(sizeof(LL_Node));

	(*n).data = value;
	(*n).next = NULL;

	return n;
}

void kd_linked_list_node_free(LL_Node* node)
{
	free(node);
}

int kd_linked_list_length(LinkedList* linked_list)
{
	int count = 0;

	LL_Node* current = (*linked_list).head;
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

	LL_Node* current = (*linked_list).head;
	LL_Node* prev;

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

	LL_Node* new_next_node = current;
	LL_Node* insert_node = kd_linked_list_node_new(value);

	(*insert_node).next = new_next_node;
	(*prev).next = insert_node;
}

void kd_linked_list_node_delete(LinkedList* linked_list, int position)
{
	if((*linked_list).head == NULL)
	{
		return;
	}

	LL_Node* current = (*linked_list).head;

	if(position == 0)
	{
		(*linked_list).head = (*((*linked_list).head)).next;
		kd_linked_list_node_free(current);

		return;
	}

	LL_Node* prev;

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

	LL_Node* node_new = (*current).next;
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
	LL_Node* node_new = kd_linked_list_node_new(value);
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
	LL_Node* current = (*linked_list).head;
	while((*current).next != NULL)
	{
		current = (*current).next;
	}

	LL_Node* node_new = NULL; 
	node_new = kd_linked_list_node_new(value);
	(*current).next = node_new;
}


int _kd_linked_list_node_get(LL_Node* node)
{
	return (*node).data;
}

int kd_linked_list_get(LinkedList* linked_list, int position)
{
	LL_Node* current = (*linked_list).head;
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

	LL_Node* current = (*linked_list).head;
	while(current != NULL)
	{
		kd_linked_list_append(linked_list_new, _kd_linked_list_node_get(current));
		current = (*current).next;
	}

	return linked_list_new;
}
