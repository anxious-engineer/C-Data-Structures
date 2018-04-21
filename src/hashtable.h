#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

typedef struct HashtableItem{
  char * key;
  void * data;
} HashtableItem;

HashtableItem * create_HashtableItem(char * key, void * data);

typedef struct Hashtable{
  LL ** table;
  int size;
} Hashtable;

Hashtable * create_Hashtable(int size);

void free_Hashtable(Hashtable * target);

int hash(Hashtable * table, char * key);

int insert(Hashtable * table, char * key, void * data);

int remove_key(Hashtable * table, char * target_key);

void * lookup_key(Hashtable * table, char * target_key);

void print_hashtable(Hashtable * table);

#endif
