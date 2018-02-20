#include "multilevel_queue.h"

// START MLQ TYPE DEFINITION/FUNCTIONS
MLQ * create_MLQ(int num_levels){
  // num_levels must be atleast 2
  if(num_levels < 2) {
    perror("Error creating MLQ in create_MLQ().\n\tA MLQ must have atleast 2 levels.");
    return NULL;
  }
  // Allocate space for Queues
  // - return NULL if error
  // - dealloc struct if error
  Queue ** newQS = (Queue**) malloc(sizeof(Queue*) * num_levels);
  // - Check for unsuccessful QueueNode malloc
  if(newQS == NULL) {
    perror("Error allocating memory for new newQS in create_MLQ().");
    return NULL;
  }

  // Build Queue
  // Create Queues until failure
  int i = 0;
  for(i = 0; i < num_levels; i++){
    Queue * newQ = create_Queue();

    // Check for Queue Creation Failure
    if(newQ == NULL) {
      perror("Error creating a Queue in create_MLQ().");
      // Free Allocated Qs and return NULL
      // Free from 0 to i (i.e. all the levels allocated so far)
      int f = 0;
      for(f = 0; f < i; f++){
        free_Queue(newQS[f]);
      }
      // Free Pointer Array
      free(newQS);
      return NULL;
    }

    // Otherwise store newQ
    newQS[i] = newQ;
  }

  // Build Struct
  MLQ * newMLQ = (MLQ*) malloc(sizeof(MLQ));
  // - Check for unsuccessful MLQ malloc
  if(newMLQ == NULL) {
    perror("Error allocating memory for new MLQ in create_MLQ().");
    // Free those Queues
    int f = 0;
    for(f = 0; f < num_levels; f++){
      free_Queue(newQS[f]);
    }
    // Free Pointer Array
    free(newQS);
    return NULL;
  }
  // Populate Struct
  *newMLQ = (MLQ) {
    .qs = newQS,
    .levels = num_levels,
    .size = 0
  };
  // Return ptr
  return newMLQ;
}

// TODO : ADD NULL POINTER CHECK
// Free a MLQ
void free_MLQ(MLQ * mlq){
  // Free all Queues
  int i = 0;
  for(i = 0; i < mlq->levels; i++){
    free_Queue(mlq->qs[i]);
  }
  // Free Pointer array
  free(mlq->qs);
  // Free Struct
  free(mlq);
}

// MLQ levels go from 0 to (levels - 1)
// Validates if a level is in the bounds of a MLQ
// 0 - Out of Bounds
// 1 - Valid Level
int validate_level(MLQ * mlq, int level){
  if(level >= mlq->levels){
    perror("Error MLQ Level out of bounds.");
    return 0;
  }
  return 1;
}

// Enqueue a level in a MLQ
int enqueue_level(MLQ * mlq, int level, void* data){
  // Make sure its a valid level
  // - return -1 if not valid level
  if(validate_level(mlq, level) == 0){
    return -1;
  }
  // Get queue
  Queue * q = mlq->qs[level];
  // Get Level Size before
  int old_level_size = get_queue_size(q);
  int new_level_size = enqueue(q, data);
  // Check for enqueue error
  if(new_level_size == -1){
    perror("Error in equeue() in enqueue_level().");
    return -1;
  }
  // Update MLQ size
  mlq->size -= old_level_size;
  mlq->size += new_level_size;
  return mlq->size;
}

// Dequeue a level in a MLQ
void* dequeue_level(MLQ * mlq, int level){
  // Make sure its a valid level
  // - return null if not valid level
  if(validate_level(mlq, level) == 0){
    return NULL;
  }
  // Get queue
  Queue * q = mlq->qs[level];
  void* data = dequeue(q);
  // Check for unsuccessful dequeue
  if(data == NULL){
    return NULL;
  }
  // Update MLQ size
  mlq->size -= 1;
  // Return data
  return data;
}

// Peek a level in a MLQ
void* peek_level(MLQ * mlq, int level){
  // Make sure its a valid level
  // - return null if not valid level
  if(validate_level(mlq, level) == 0){
    return NULL;
  }
  // Get queue
  Queue * q = mlq->qs[level];
  return peek(q);
}

// Get the number of nodes in a level in a MLQ
int get_level_size(MLQ * mlq, int level){
  // Make sure its a valid level
  // - return -1 if not valid level
  if(validate_level(mlq, level) == 0){
    return -1;
  }
  // Get queue
  Queue * q = mlq->qs[level];
  return get_queue_size(q);
}

// Get the total number of nodes in a MLQ
int get_MLQ_size(MLQ * mlq){
  return mlq->size;
}
// END MLQ TYPE DEFINITION/FUNCTIONS
