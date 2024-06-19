// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h> // For size_t

typedef struct
{
  int *data;
  size_t size;
  size_t capacity;
} ArrayList;

// Function prototypes
ArrayList *create_array_list(size_t initial_capacity);
void add_element(ArrayList *list, int element);
int get_element(ArrayList *list, size_t index);
void remove_element(ArrayList *list, size_t index);
void free_array_list(ArrayList *list);
void resize_if_needed(ArrayList *list);
void print_array(const ArrayList *list);
void set_element(ArrayList *list, size_t index, int value);
void reverse_array_list(ArrayList *list);

#endif // ARRAYLIST_H
