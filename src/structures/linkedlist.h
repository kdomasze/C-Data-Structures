#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node_t;
struct LinkedList_t;

typedef struct Node_t
{
	int data;
	struct Node_t* next;
} Node;

typedef struct LinkedList_t
{
	struct Node_t* head;
} LinkedList;


/*
 * initializes an empty linked list
 */
LinkedList* kd_linked_list_new();

/*
 * frees a given linked list from memory
 */
void kd_linked_list_free(LinkedList* linked_list);

/*
 * initializes a new node with a value
 */
Node* kd_linked_list_node_new(int value);

/*
 * frees a given node from memory
 */
void kd_linked_list_node_free(Node* node);

/*
 * returns the length of a linked list
 */
int kd_linked_list_length(LinkedList* linked_list);

/*
 * inserts a node at the given position, moving the
 * element origionally in that position to position + 1
 *
 * by default, the function will append the created node to
 * the end of the linked list if the position exceeds the 
 * length of the linked list (with an empty list defaulting
 * with the insert as the first and only node)
 */
void kd_linked_list_insert(LinkedList* linked_list, int position, int value);

/*
 * deletes a node at the given position, moving the element in
 * position + 1 to position
 *
 * by default, if the position given is not valid for the list
 * (i.e. exceeds the length of the list), the function will
 * not modify the list
 */
void kd_linked_list_node_delete(LinkedList* linked_list, int position);

/*
 * adds a node to the beginning of the linked list
 */
void kd_linked_list_push(LinkedList* linked_list, int value);

/*
 * adds a node to the end of the linked list
 */
void kd_linked_list_append(LinkedList* linked_list, int value);

/*
 * returns the data stored in a node
 */
int kd_linked_list_get(Node* n);

/*
 * returns a copy of the linked list
 */
LinkedList* kd_linked_list_copy(LinkedList* linked_list);

/*
 * prints entire linked list into console
 */
void _kd_linked_list_print_all(LinkedList* linked_list);

#endif
