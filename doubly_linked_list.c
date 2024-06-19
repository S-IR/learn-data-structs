#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int value;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct
{
  int length;
  Node *head;
  Node *tail;
} DoublyLinkedList;

Node *createNode(int data);
void prepend(DoublyLinkedList *dl, int item);
void insertAt(DoublyLinkedList *dl, int item, int index);
void append(DoublyLinkedList *dl, int item);
int removeItem(DoublyLinkedList *dl, int item); // Renamed to avoid conflict with stdio.h
Node *getAt(DoublyLinkedList *dl, int index);
int get(DoublyLinkedList *dl, int index);
void removeAt(DoublyLinkedList *dl, int index);
int removeNode(DoublyLinkedList *dl, Node *node);
void printList(DoublyLinkedList *dl);

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void prepend(DoublyLinkedList *dl, int item)
{
  Node *node = createNode(item);
  if (dl->head == NULL)
  {
    dl->head = dl->tail = node;
  }
  else
  {
    node->next = dl->head;
    dl->head->prev = node;
    dl->head = node;
  }
  dl->length++;
}

void insertAt(DoublyLinkedList *dl, int item, int index)
{
  if (index > dl->length)
  {
    fprintf(stderr, "You cannot insert here, %d is greater than the length of the doubly linked list\n", index);
    return;
  }
  if (index == dl->length)
  {
    append(dl, item);
    return;
  }
  if (index == 0)
  {
    prepend(dl, item);
    return;
  }

  Node *curr = getAt(dl, index);
  Node *newNode = createNode(item);

  newNode->next = curr;
  newNode->prev = curr->prev;
  curr->prev->next = newNode;
  curr->prev = newNode;

  dl->length++;
}

void append(DoublyLinkedList *dl, int item)
{
  Node *newNode = createNode(item);
  if (dl->tail == NULL)
  {
    dl->head = dl->tail = newNode;
  }
  else
  {
    newNode->prev = dl->tail;
    dl->tail->next = newNode;
    dl->tail = newNode;
  }
  dl->length++;
}

int removeItem(DoublyLinkedList *dl, int item)
{
  Node *curr = dl->head;
  int i = 0;
  while (curr != NULL)
  {
    if (curr->value == item)
    {
      removeNode(dl, curr);
      return i;
    }
    curr = curr->next;
    i++;
  }
  fprintf(stderr, "No node found for item %d\n", item);
  return -1;
}

Node *getAt(DoublyLinkedList *dl, int index)
{
  if (index < 0 || index >= dl->length)
  {
    return NULL;
  }
  Node *curr = dl->head;
  for (int i = 0; i < index; i++)
  {
    curr = curr->next;
  }
  return curr;
}

void removeAt(DoublyLinkedList *dl, int index)
{
  Node *node = getAt(dl, index);
  if (node != NULL)
  {
    removeNode(dl, node);
  }
}

int get(DoublyLinkedList *dl, int index)
{
  Node *node = getAt(dl, index);
  if (node != NULL)
  {
    return node->value;
  }
  fprintf(stderr, "Index %d is out of bounds\n", index);
  return -1;
}

int removeNode(DoublyLinkedList *dl, Node *node)
{
  if (node == NULL)
  {
    return -1;
  }

  if (node->prev != NULL)
  {
    node->prev->next = node->next;
  }
  else
  {
    dl->head = node->next;
  }

  if (node->next != NULL)
  {
    node->next->prev = node->prev;
  }
  else
  {
    dl->tail = node->prev;
  }

  int val = node->value;
  free(node);
  dl->length--;
  return val;
}

void printList(DoublyLinkedList *dl)
{
  Node *current = dl->head;
  while (current != NULL)
  {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

void testDoublyLinkedList()
{
  DoublyLinkedList dl = {0, NULL, NULL};

  // Test append
  append(&dl, 10);
  append(&dl, 20);
  append(&dl, 30);
  printf("List after appending 10, 20, 30: ");
  printList(&dl);

  // Test prepend
  prepend(&dl, 0);
  printf("List after prepending 0: ");
  printList(&dl);

  // Test insertAt
  insertAt(&dl, 15, 2);
  printf("List after inserting 15 at index 2: ");
  printList(&dl);

  // Test get
  int value = get(&dl, 3);
  printf("Value at index 3: %d\n", value);

  // Test remove
  int index = removeItem(&dl, 20);
  printf("List after removing value 20: ");
  printList(&dl);
  printf("Removed value 20 at index: %d\n", index);

  // Test removeAt
  removeAt(&dl, 1);
  printf("List after removing value at index 1: ");
  printList(&dl);

  // Test get with out of bounds index
  value = get(&dl, 10);
  printf("Value at out-of-bounds index 10: %d\n", value);

  // Test removeNode directly
  Node *node = getAt(&dl, 1);
  int removedValue = removeNode(&dl, node);
  printf("List after removing node with value %d: ", removedValue);
  printList(&dl);
}

int main()
{
  testDoublyLinkedList();
  return 0;
}
