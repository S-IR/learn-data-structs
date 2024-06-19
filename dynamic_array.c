#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void reverse_array_list(ArrayList *list)
{
  if (list->size <= 1)
  {
    return; // No need to reverse if there are 0 or 1 elements
  }

  size_t left = 0;
  size_t right = list->size - 1;

  while (left < right)
  {
    // Swap elements at left and right indices
    int temp = list->data[left];
    list->data[left] = list->data[right];
    list->data[right] = temp;

    // Move to the next pair of elements
    left++;
    right--;
  }
}

ArrayList *create_array_list(size_t initial_capacity)
{
  ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
  list->data = (int *)malloc(initial_capacity * sizeof(int));
  list->size = 0;
  list->capacity = initial_capacity;
  return list;
}

void add_element(ArrayList *list, int element)
{
  resize_if_needed(list);
  list->data[list->size++] = element;
}
int get_element(ArrayList *list, size_t index)
{
  if (index >= list->size)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  return list->data[index];
}

void set_element(ArrayList *list, size_t index, int value)
{
  if (index >= list->size)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  list->data[index] = value;
}

void remove_element(ArrayList *list, size_t index)
{
  if (index >= list->size)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  for (size_t i = index; i < list->size - 1; ++i)
  {
    list->data[i] = list->data[i + 1];
  }
  list->size--;
}

void free_array_list(ArrayList *list)
{

  free(list->data);
  free(list);
}

void resize_if_needed(ArrayList *list)
{
  if (list->size >= list->capacity)
  {
    list->capacity *= 2;
    list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
  }
}
void print_array(const ArrayList *list)
{
  printf("ArrayList: ");
  for (size_t i = 0; i < list->size; ++i)
  {
    printf("%d ", list->data[i]);
  }
  printf("\n");
}