#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int value;
  struct Node *prev;
};
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->value = data;
  newNode->prev = NULL;
  return newNode;
}

struct Stack
{
  struct Node *head;
  int length;
};
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Stack *createStack()
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->head = NULL;
  stack->length = 0;
  return stack;
}

int peek(struct Stack *stack)
{
  if (stack->head == NULL)
  {
    printf("This stack is empty\n");
    return -1;
  }
  return stack->head->value;
}

void push(struct Stack *stack, int data)
{
  struct Node *node = createNode(data);
  stack->length++;
  if (stack->head == NULL)
  {
    stack->head = node;
    return;
  }
  node->prev = stack->head;
  stack->head = node;
}

int pop(struct Stack *stack)
{
  if (stack->head == NULL)
  {
    printf("This stack is empty\n");
    return -1;
  }

  struct Node *head = stack->head;
  int val = head->value;
  stack->head = head->prev;
  stack->length--;
  free(head);

  return val;
}