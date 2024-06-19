#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

typedef struct Queue
{
  struct Node *head;
  struct Node *tail;
  int length;
} Queue;
Queue *createQueue();
int peek(Queue *queue);
int dequeue(Queue *queue);
void enqueue(Queue *queue, int data);
void printQueue(Queue *queue);
void freeQueue(Queue *queue);

#endif