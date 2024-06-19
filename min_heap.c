#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"

MinHeap *create_min_heap()
{
  MinHeap *newMinHeap = (MinHeap *)malloc(sizeof(MinHeap));
  if (newMinHeap == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newMinHeap->length = 0;
  newMinHeap->data = create_array_list(5);
  return newMinHeap;
}

int min_heap_parent(int index)
{
  return (index - 1) / 2;
}

int min_heap_left_child(int index)
{
  return index * 2 + 1;
}

int min_heap_right_child(int index)
{
  return index * 2 + 2;
}

void min_heap_heapify_down(MinHeap *minHeap, int index)
{
  int leftIndex = min_heap_left_child(index);
  int rightIndex = min_heap_right_child(index);
  int smallest = index;

  if (leftIndex < minHeap->length && get_element(minHeap->data, leftIndex) < get_element(minHeap->data, smallest))
  {
    smallest = leftIndex;
  }

  if (rightIndex < minHeap->length && get_element(minHeap->data, rightIndex) < get_element(minHeap->data, smallest))
  {
    smallest = rightIndex;
  }

  if (smallest != index)
  {
    int smallestValue = get_element(minHeap->data, smallest);
    int currentValue = get_element(minHeap->data, index);
    set_element(minHeap->data, index, smallestValue);
    set_element(minHeap->data, smallest, currentValue);
    min_heap_heapify_down(minHeap, smallest);
  }
}

void min_heap_heapify_up(MinHeap *minHeap, int index)
{
  while (index > 0)
  {
    int parentIndex = min_heap_parent(index);
    int parentValue = get_element(minHeap->data, parentIndex);
    int currentValue = get_element(minHeap->data, index);

    if (parentValue <= currentValue)
    {
      break;
    }

    set_element(minHeap->data, index, parentValue);
    set_element(minHeap->data, parentIndex, currentValue);
    index = parentIndex;
  }
}

void min_heap_insert(MinHeap *minHeap, int value)
{
  if (minHeap->length == minHeap->data->size)
  {
    add_element(minHeap->data, value);
  }
  else
  {
    set_element(minHeap->data, minHeap->length, value);
  }
  min_heap_heapify_up(minHeap, minHeap->length);
  minHeap->length++;
}

int min_heap_delete(MinHeap *minHeap)
{
  if (minHeap->length == 0)
  {
    return -1;
  }

  int rootValue = get_element(minHeap->data, 0);
  int lastValue = get_element(minHeap->data, minHeap->length - 1);
  set_element(minHeap->data, 0, lastValue);
  minHeap->length--;
  min_heap_heapify_down(minHeap, 0);

  return rootValue;
}

void free_min_heap(MinHeap *minHeap)
{
  free_array_list(minHeap->data);
  free(minHeap);
}
#include <stdio.h>
#include "min_heap.h"

int main()
{
  MinHeap *minHeap = create_min_heap();

  // Insert elements into the min heap
  min_heap_insert(minHeap, 10);
  min_heap_insert(minHeap, 4);
  min_heap_insert(minHeap, 7);
  min_heap_insert(minHeap, 1);
  min_heap_insert(minHeap, 8);
  min_heap_insert(minHeap, 5);

  // Print the min heap
  printf("Min heap: ");
  print_array(minHeap->data);

  // Delete the minimum element
  printf("Deleted element: %d\n", min_heap_delete(minHeap));

  // Print the min heap after deletion
  printf("Min heap after deletion: ");
  print_array(minHeap->data);

  // Free the min heap
  free_min_heap(minHeap);

  return 0;
}
