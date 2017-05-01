#include "queue.h"

Queue* kd_queue_new()
{
	return kd_linked_list_new();
}

void kd_queue_free(Queue* queue)
{
	kd_linked_list_free(queue);
}

void kd_queue_push(Queue* queue, int value)
{
	kd_linked_list_append(queue, value);
}

int kd_queue_pop(Queue* queue)
{
	int value = kd_linked_list_get(queue, 0);
	kd_linked_list_node_delete(queue, 0);

	return value;
}
