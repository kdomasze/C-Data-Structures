#include <stdio.h>
#include "../structures/linkedlist.h"

void test_linked_list()
{
	int test_values[7] = {10, 20, 30, 40, 50, 60, 70};

	LinkedList* linked_list = kd_linked_list_new();
	
	kd_linked_list_node_delete(linked_list, 0);

	int i;
	for(i = 0; i < 7; i++)
	{
		kd_linked_list_insert(linked_list, i, test_values[i]);
	}

	for(i = 0; i < 7; i++)
	{
		if(kd_linked_list_get(linked_list, i) == test_values[i])
		{
			printf("%d == %d\n", kd_linked_list_get(linked_list, i), test_values[i]);
		}
		else
		{
			printf("%d != %d\n", kd_linked_list_get(linked_list, i), test_values[i]);
		}
	}

	for(i = 0; i < 7; i++)
	{
		kd_linked_list_node_delete(linked_list, 0);
	}

	for(i = 0; i < 7; i++)
	{
		kd_linked_list_append(linked_list, test_values[i]);
	}

	for(i = 0; i < 7; i++)
	{
		if(kd_linked_list_get(linked_list, i) == test_values[i])
		{
			printf("%d == %d\n", kd_linked_list_get(linked_list, i), test_values[i]);
		}
		else
		{
			printf("%d != %d\n", kd_linked_list_get(linked_list, i), test_values[i]);
		}
	}

	for(i = 0; i < 7; i++)
	{
		kd_linked_list_node_delete(linked_list, 0);
	}

	for(i = 0; i < 7; i++)
	{
		kd_linked_list_push(linked_list, test_values[i]);
	}

	for(i = 6; i <= 0; i--)
	{
		if(kd_linked_list_get(linked_list, i) == test_values[i])
		{
			printf("%d == %d\n", kd_linked_list_get(linked_list, i), test_values[i]);
		}
		else
		{
			printf("%d != %d\n", kd_linked_list_get(linked_list, i), test_values[i]);
		}
	}
	
	LinkedList* linked_list_copy = kd_linked_list_copy(linked_list);

	for(i = 0; i < 7; i++)
	{
		if(kd_linked_list_get(linked_list, i) == kd_linked_list_get(linked_list_copy, i))
		{
			printf("%d == %d\n", kd_linked_list_get(linked_list, i), kd_linked_list_get(linked_list_copy, i));
		}
		else
		{
			printf("%d != %d\n", kd_linked_list_get(linked_list, i), kd_linked_list_get(linked_list_copy, i));
		}
	}

	kd_linked_list_free(linked_list_copy);
	kd_linked_list_free(linked_list);
}
