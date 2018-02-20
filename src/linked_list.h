#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

// START LL TYPE DEFINITION/FUNCTIONS

typedef struct LLNode LLNode;
struct LLNode{
  void* data;
  LLNode* next;
};

typedef struct LL{
  LLNode * head;
  int length;
} LL;

LL * create_LL();

void free_LL();

int push(LL * list, void* data);

void* pop(LL * list);

int remove_target(LL * list, void* target_data);

// END LL TYPE DEFINITION/FUNCTIONS

#endif
