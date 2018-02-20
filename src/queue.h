#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

// START QUEUE TYPE DEFINITION/FUNCTIONS

typedef struct QueueNode QueueNode;

struct QueueNode {
  void* data;
  QueueNode* next;
};

typedef struct Queue{
  QueueNode* head;
  QueueNode* tail;
  int size;
} Queue;

Queue * create_Queue();

void free_Queue(Queue * q);

int enqueue(Queue* q, void* data);

void* dequeue(Queue* q);

void* peek(Queue* q);

int get_queue_size(Queue* q);

// END QUEUE TYPE DEFINITION/FUNCTIONS

#endif
