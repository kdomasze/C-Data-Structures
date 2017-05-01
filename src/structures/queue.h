#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

typedef struct LinkedList_t Queue;

/*
 * allocates a new queue
 */
Queue* kd_queue_new();

/*
 * frees the given queue from memory
 */
void kd_queue_free(Queue* queue);

/*
 * pushes the given value to the end of the given queue
 */
void kd_queue_push(Queue* queue, int value);

/*
 * removes the head element from the queue and returns that value
 */
int kd_queue_pop(Queue* queue);

#endif
