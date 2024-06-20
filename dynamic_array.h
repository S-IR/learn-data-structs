#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h> // For size_t

typedef struct
{
  void **data;
  size_t size;
  size_t capacity;
} ArrayList;

// Function prototypes
ArrayList *create_array_list(size_t initial_capacity);
void add_element(ArrayList *list, void *element);
void *get_element(ArrayList *list, size_t index);
void remove_element(ArrayList *list, size_t index);
void free_array_list(ArrayList *list);
void resize_if_needed(ArrayList *list);
void print_array(const ArrayList *list);
void set_element(ArrayList *list, size_t index, void *value);
void reverse_array_list(ArrayList *list);

#endif // DYNAMIC_ARRAY_H
