#include "stack.h"

Stack* kd_stack_new()
{
	return kd_linked_list_new();
}

void kd_stack_free(Stack* stack)
{
	kd_linked_list_free(stack);
}

void kd_stack_push(Stack* stack, int value)
{
	kd_linked_list_push(stack, value);
}

int kd_stack_pop(Stack* stack)
{
	int value = kd_linked_list_get(stack, 0);
	kd_linked_list_node_delete(stack, 0);

	return value;
}
