#include "queue.h"

// START QUEUE TYPE DEFINITION/FUNCTIONS

// Builds new Queue
// Returns NULL on Error
Queue * create_Queue(){
  // Allocate space
  // - Return NULL on error
  Queue * newQ = (Queue*) malloc(sizeof(Queue));
  // - Check for unsuccessful Queue malloc
  if(newQ == NULL) {
    perror("Error allocating memory for new Queue in create_Queue().");
    return NULL;
  }
  // build struct
  *newQ = (Queue) {
    .head = NULL,
    .tail = NULL,
    .size = 0
  };
  // return ptr
  return newQ;
}

// TODO : ADD NULL POINTER CHECK
// Frees a Queue
void free_Queue(Queue * q){
  // Free all nodes, but not their data
  if(q->size > 0){
    // Hooray we can just dequeue them
    while(dequeue(q) != NULL);
  }
  // Free struct
  free(q);
}

// Returns size of queue if succesful
// Returns -1 if unsuccessful
int enqueue(Queue* q, void* data){
  // Build New node for data
  // - Error if malloc fails
  QueueNode * newNode = (QueueNode*) malloc(sizeof(QueueNode));
  // - Check for unsuccessful QueueNode malloc
  if(newNode == NULL) {
    perror("Error allocating memory for new QueueNode in enqueue().");
    return -1;
  }
  // - build node
  *newNode = (QueueNode) {
    .data = data,
    .next = NULL
  };

  // Append to and update tail
  // - if size is 0 make head and tail
  if(q->size == 0){
    q->head = newNode;
    q->tail = newNode;
  } else {
    // Point old tail to newNode
    // newNode is now new tail
    q->tail->next = newNode;
    q->tail = newNode;
  }
  // Increment size and return
  q->size += 1;
  return q->size;
}

// Returns Data of head node and destroys said node
// Returns NULL if size < 1
void* dequeue(Queue* q){
  // Make sure Size > 0
  // Return NULL if empty
  if(q->size < 1) {
    return NULL;
  }
  // Get ptr
  QueueNode * outgoingNode = q->head;
  // Delink node
  // - update head
  q->head = q->head->next;
  // Decrement size
  q->size -= 1;
  // Collect Data
  void* data = outgoingNode->data;
  // Free memory
  free(outgoingNode);
  // return data
  return data;
}

// Returns data in head node
// Returns null if size < 1
void* peek(Queue* q){
  // Make sure Size > 1
  if(q->size < 1) {
    return NULL;
  }
  // Return head data
  return q->head->data;
}

// return queue size
int get_queue_size(Queue* q){
 return q->size;
}

// END QUEUE TYPE DEFINITION/FUNCTIONS
