#include "hashtable.h"

// Create a new Hashtable
Hashtable * create_Hashtable(int size){

  // Allocate space for table ("buckets") Hashtable
  // - return NULL if error
  LL ** newBuckets = (LL**) malloc(sizeof(LL *) * size);
  // - Check for unsuccessful table malloc
  if(newBuckets == NULL) {
    perror("Error allocating memory for new buckets in create_Hashtable().");
    return NULL;
  }

  // Allocate space for a Hashtable
  // - return NULL if error
  Hashtable * newHashtable = (Hashtable*) malloc(sizeof(Hashtable));
  // - Check for unsuccessful Hashtable malloc
  if(newHashtable == NULL) {
    free(newBuckets);
    perror("Error allocating memory for new LL in create_LL().");
    return NULL;
  }

  // Nullify buckets
  int i = 0;
  for (i = 0; i < size; i++) {
    newBuckets[i] = NULL;
  }

  // Build Struct
  *newHashtable = (Hashtable) {
    .table = newBuckets,
    .size = size
  };
}

// TODO : ADD NULL POINTER CHECK
// Free a Hashtable
void free_Hashtable(Hashtable * target){
  // Determine if any buckets need to be freed
  int i = 0;
  for (i = 0; i < target->size; i++) {
    if (target->table[i] != NULL){
      free_LL(target->table[i]);
    }

  }
  // Free Buckets
  free(target->table);
  // Free Struct
  free(target);
}

// TODO : Implement Something for Complex like djb2 or Adler32
// Very primitive hash function
int hash(Hashtable * table, char * key){
  if (key == NULL) {
    perror("Error hasing a NULL key in hash().");
    return -1;
  }
  int value = 1;
  int i = 0;
  for (i = 0; i < strlen(key); i++) {
    value = (value * key[i]) % table->size;
  }
  return value;
}

// Insert data with a given key into a Hashtable
int insert(Hashtable * table, char * key, void * data){
  if (key == NULL) {
    perror("Error inserting NULL key in insert().");
    return -1;
  }

  // Get hash_value
  int hash_value = hash(table, key);
  if (hash_value < 0) {
    return -1;
  }

  // Get bucket to place data in
  LL * bucket = table->table[hash_value];
  // Create List if bucket doesn't have one yet
  if (bucket == NULL) {
    bucket = create_LL();
  }

  // Append data to bucket
  push(bucket, data);
  return 1;
}

// Remove data with a given key into a Hashtable
int remove_key(Hashtable * table, char * target_key, void * data){
  if (target_key == NULL) {
    perror("Error inserting NULL key in remove_key().");
    return -1;
  }

  // Get hash_value
  int hash_value = hash(table, target_key);
  if (hash_value < 0) {
    return -1;
  }

  // Get bucket to place data in
  LL * bucket = table->table[hash_value];
  // Create List if bucket doesn't have one yet
  if (bucket == NULL) {
    perror("Key mapped to empty bucket in remove_key().");
    return -1;
  }

  // Remove data from bucket
  remove_target(bucket, data);
  return 1;
}

int main(int argc, char const *argv[]) {
  printf("**** Hashtable Test ****");
  return 0;
}
