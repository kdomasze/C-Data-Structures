#include "../structures/linkedlist.h"

void dummytest()
{
	LinkedList* linked_list = kd_linked_list_new();
	
	LinkedList* linked_list_2 = kd_linked_list_new();
	_kd_linked_list_print_all(linked_list_2);
	kd_linked_list_free(linked_list_2);

	kd_linked_list_node_delete(linked_list, 0);
	kd_linked_list_insert(linked_list, 7, 55);
	_kd_linked_list_print_all(linked_list);
	
	kd_linked_list_append(linked_list, 1);
	kd_linked_list_append(linked_list, 2);
	kd_linked_list_append(linked_list, 3);
	kd_linked_list_append(linked_list, 4);	
	kd_linked_list_append(linked_list, 5);
	kd_linked_list_append(linked_list, 6);
	_kd_linked_list_print_all(linked_list);

	kd_linked_list_push(linked_list, 911);
	_kd_linked_list_print_all(linked_list);

	kd_linked_list_insert(linked_list, 3, 10);
	_kd_linked_list_print_all(linked_list);

	kd_linked_list_insert(linked_list, 20, 111);
	_kd_linked_list_print_all(linked_list);

	kd_linked_list_node_delete(linked_list, 1);
	_kd_linked_list_print_all(linked_list);

	kd_linked_list_node_delete(linked_list, 0);
	_kd_linked_list_print_all(linked_list);

	LinkedList* linked_list_3 = kd_linked_list_copy(linked_list);
	_kd_linked_list_print_all(linked_list_3);
	kd_linked_list_free(linked_list_3);

	kd_linked_list_free(linked_list);
}
