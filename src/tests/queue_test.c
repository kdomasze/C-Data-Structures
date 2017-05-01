#include <stdio.h>
#include "../structures/queue.h"

void test_queue()
{
	int test_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	Queue* queue = kd_queue_new();

	int i;
	for(i = 0; i < 8; i++)
	{
		kd_queue_push(queue, test_data[i]);
	}

	for(i = 0; i < 8; i++)
	{
		int res = kd_queue_pop(queue);

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
		kd_queue_push(queue, test_data[i]);
	}

	kd_queue_free(queue);
}
