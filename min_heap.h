#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "dynamic_array.h"

typedef struct MinHeap
{
  int length;
  ArrayList *data;
} MinHeap;

MinHeap *create_min_heap();
void min_heap_insert(MinHeap *minHeap, int value);
int min_heap_delete(MinHeap *minHeap);
int min_heap_parent(int index);
int min_heap_left_child(int index);
int min_heap_right_child(int index);
void min_heap_heapify_up(MinHeap *minHeap, int index);
void min_heap_heapify_down(MinHeap *minHeap, int index);
void free_min_heap(MinHeap *minHeap);

#endif /* MIN_HEAP_H */
