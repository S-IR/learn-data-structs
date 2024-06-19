#include <stdlib.h>
#include <stdio.h>
#include "queue_list.h"

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

Queue *createQueue()
{
  Queue *newQueue = (Queue *)malloc(sizeof(Queue));
  newQueue->head = newQueue->tail = NULL;
  newQueue->length = 0;
  return newQueue;
}

int peek(Queue *queue)
{
  if (queue->head == NULL)
  {
    return -1;
  }
  return queue->head->value;
}
int dequeue(Queue *queue)
{
  if (queue->head == NULL)
  {
    printf("This queue is empty");
    return -1;
  }

  queue->length--;
  Node *head = queue->head;
  queue->head = queue->head->next;

  int value = head->value;
  if (queue->length == 0)
  {
    queue->tail = NULL;
  }
  free(head);
  return value;
}

void enqueue(Queue *queue, int data)
{
  queue->length++;
  Node *node = createNode(data);
  if (queue->tail == NULL)
  {
    queue->tail = queue->head = node;
  }

  queue->tail->next = node;
  queue->tail = node;
}
void printQueue(Queue *queue)
{
  Node *temp = queue->head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->value);
    temp = temp->next;
  }
  printf("NULL\n");
}
// Function to free the queue
void freeQueue(Queue *queue)
{
  Node *temp;
  while (queue->head != NULL)
  {
    temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
  }
  free(queue);
}
// int main()
// {
//   Queue *queue = createQueue(); // Initialize the queue

//   // Enqueue elements
//   enqueue(queue, 10);
//   enqueue(queue, 20);
//   enqueue(queue, 30);
//   enqueue(queue, 40);

//   // Print the queue
//   printf("Queue: ");
//   printQueue(queue);

//   // Dequeue elements
//   printf("Dequeued: %d\n", dequeue(queue));
//   printf("Dequeued: %d\n", dequeue(queue));

//   // Print the queue again
//   printf("Queue after dequeuing: ");
//   printQueue(queue);

//   // Free the queue
//   freeQueue(queue);

//   return 0;
// }

// Node
// {
//   int data;
//   Node *next;
// };

// Queue
// {
//   Node *front;
//   Node *rear;
//   int length;
// };

// Node *createNode(int data)
// {
//   Node *newNode = (Node *)malloc(sizeof(Node));
//   newNode->data = data;
//   newNode->next = NULL;
//   return newNode;
// }

// Queue *createQueue()
// {
//   Queue *queue = (Queue *)malloc(sizeof(Queue));
//   queue->front = queue->rear = NULL;
//   return queue;
// }

// void enqueue(Queue *queue, int data)
// {
//   Node *newNode = createNode(data);
//   if (queue->rear == NULL)
//   {
//     queue->front = queue->rear = newNode;
//   }
//   else
//   {
//     queue->rear->next = newNode;
//     queue->rear = newNode;
//   }
//   queue->length++;
// }

// int dequeue(Queue *queue)
// {
//   if (queue->front == NULL)
//   {
//     printf("Queue is empty\n");
//     return -1; // Or an appropriate error code or handling
//   }
//   Node *temp = queue->front;
//   int data = temp->data;
//   queue->front = queue->front->next;
//   if (queue->front == NULL)
//   {
//     queue->rear = NULL;
//   }
//   free(temp);
//   queue->length--;
//   return data;
// }

// int peek(Queue *queue)
// {
//   if (queue->front == NULL)
//   {
//     return -1;
//   }
//   return queue->front->data;
// };
// // Function to print the queue
// void printQueue(Queue *queue)
// {
//   Node *temp = queue->front;
//   while (temp != NULL)
//   {
//     printf("%d -> ", temp->data);
//     temp = temp->next;
//   }
//   printf("NULL\n");
// }
// // Function to free the queue
// void freeQueue(Queue *queue)
// {
//   Node *temp;
//   while (queue->front != NULL)
//   {
//     temp = queue->front;
//     queue->front = queue->front->next;
//     free(temp);
//   }
//   free(queue);
// }