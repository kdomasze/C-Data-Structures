#include <stdio.h>
#include "../structures/stack.h"

void test_stack()
{
	int test_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	Stack* stack = kd_stack_new();

	int i;
	for(i = 0; i < 8; i++)
	{
		kd_stack_push(stack, test_data[i]);
	}

	for(i = 7; i >= 0; i--)
	{
		int res = kd_stack_pop(stack);

		if(res != test_data[i])
		{
			printf("%d != %d\n", res, test_data[i]);
		}
		else
		{
			printf("%d == %d\n", res, test_data[i]);
		}
	}

	for(i = 0; i < 8; i++)
	{
		kd_stack_push(stack, test_data[i]);
	}

	kd_stack_free(stack);
}
