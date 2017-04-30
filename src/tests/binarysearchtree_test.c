#include <stdio.h>
#include "binarysearchtree_test.h"
#include "../structures/binarysearchtree.h"

void test_binary_search_tree()
{
	int test_data[8] = {1, 3, 0, 2, 7, 9, -2, -1};

	int delete_data_order[4] = {-2, 0, 7, 3};

	int invalid_data = 159;

	BinarySearchTree* bst = kd_binary_search_tree_new();	

	int i;
	int j;

	for(i = 0; i < 8; i++)
	{	
		kd_binary_search_tree_insert(bst, test_data[i]);

		if(kd_binary_search_tree_lookup(bst, invalid_data) == 1)
		{
			printf("Lookup found data that should not be in the tree!\n");
		}

	}

	printf("Values in tree:");

	for(i = 0; i < 8; i++)
	{
		if(kd_binary_search_tree_lookup(bst, test_data[i]) == 0)
		{
			printf("%d not found in bst.\n", test_data[i]);
		}
		else
		{
			printf(" %d,", test_data[i]);
		}
	}

	printf("\b \b\n\n");

	for(i = 0; i < 4; i++)
	{
		kd_binary_search_tree_remove(bst, delete_data_order[i]);

		printf("Value deleted: %d\n Values in tree:", delete_data_order[i]);

		for(j = 0; j < 8; j++)
		{
			if (kd_binary_search_tree_lookup(bst, test_data[j]) == 1)
			{
				printf(" %d,", test_data[j]);
			}
		}

		printf("\b \b\n\n");
	}

	kd_binary_search_tree_free(bst);
}
