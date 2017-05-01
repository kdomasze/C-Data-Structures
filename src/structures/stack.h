#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

typedef struct LinkedList_t Stack;

/*
 * allocates a new stack
 */
Stack* kd_stack_new();

/*
 * frees the given stack from memory
 */
void kd_stack_free(Stack* stack);

/*
 * pushes the given value to the front of the given stack
 */
void kd_stack_push(Stack* stack, int value);

/*
 * removes the head element from the stack and returns that value
 */
int kd_stack_pop(Stack* stack);

#endif
