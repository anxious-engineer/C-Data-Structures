#ifndef MULTILEVEL_QUEUE_H
#define MULTILEVEL_QUEUE_H
#include "queue.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

// START MLQ

typedef struct MLQ {
  Queue** qs;
  int levels;
  int size;
} MLQ;

MLQ * create_MLQ(int num_levels);

void free_MLQ(MLQ * mlq);

int validate_level(MLQ * mlq, int level);

int enqueue_level(MLQ * mlq, int level, void*data);

void* dequeue_level(MLQ * mlq, int level);

void* peek_level(MLQ * mlq, int level);

int get_level_size(MLQ * mlq, int level);

int get_MLQ_size(MLQ * mlq);

// END MLQ

#endif
