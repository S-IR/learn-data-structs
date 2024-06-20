#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

ArrayList *create_array_list(size_t initial_capacity)
{
  ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
  list->data = (void **)malloc(initial_capacity * sizeof(void *));
  list->size = 0;
  list->capacity = initial_capacity;
  return list;
}

void resize_if_needed(ArrayList *list)
{
  if (list->size >= list->capacity)
  {
    list->capacity *= 2;
    list->data = (void **)realloc(list->data, list->capacity * sizeof(void *));
  }
}

void add_element(ArrayList *list, void *element)
{
  resize_if_needed(list);
  list->data[list->size++] = element;
}

void *get_element(ArrayList *list, size_t index)
{
  if (index >= list->size)
  {
    return NULL; // Out of bounds
  }
  return list->data[index];
}

void remove_element(ArrayList *list, size_t index)
{
  if (index >= list->size)
  {
    return; // Out of bounds
  }
  memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(void *));
  list->size--;
}

void free_array_list(ArrayList *list)
{
  free(list->data);
  free(list);
}

void print_array(const ArrayList *list)
{
  for (size_t i = 0; i < list->size; i++)
  {
    printf("%p ", list->data[i]);
  }
  printf("\n");
}

void set_element(ArrayList *list, size_t index, void *value)
{
  if (index >= list->size)
  {
    return; // Out of bounds
  }
  list->data[index] = value;
}

void reverse_array_list(ArrayList *list)
{
  for (size_t i = 0; i < list->size / 2; i++)
  {
    void *temp = list->data[i];
    list->data[i] = list->data[list->size - 1 - i];
    list->data[list->size - 1 - i] = temp;
  }
}