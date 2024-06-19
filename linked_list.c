#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void appendNode(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void freeList(struct Node *head)
{
  struct Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main()
{
  struct Node *head = NULL; // Initialize the head of the list

  // Append nodes to the list
  appendNode(&head, 1);
  appendNode(&head, 2);
  appendNode(&head, 3);
  appendNode(&head, 4);

  // Print the list
  printf("Linked List: ");
  printList(head);

  // Free the list
  freeList(head);

  return 0;
}