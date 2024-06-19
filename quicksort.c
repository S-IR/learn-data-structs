#include <stdio.h>

// Function prototypes
int partition(int arr[], int lo, int hi);
void qs(int arr[], int lo, int hi);
void quick_sort(int arr[], int len);
void print_array(int arr[], int len);

int partition(int arr[], int lo, int hi)
{
  int pivot = arr[hi];

  int index = lo - 1;
  for (int i = lo; i < hi; i++)
  {
    if (arr[i] <= pivot)
    {
      index++;
      int temp = arr[i];
      arr[i] = arr[index];
      arr[index] = temp;
    }
  }
  index++;
  arr[hi] = arr[index];
  arr[index] = pivot;
  return index;
}
void qs(int arr[], int lo, int hi)
{
  if (lo >= hi)
  {
    return;
  }

  int pivotIndex = partition(arr, lo, hi);
  qs(arr, lo, pivotIndex - 1);
  qs(arr, pivotIndex + 1, hi);
}
void quick_sort(int arr[], int len)
{
  qs(arr, 0, len - 1);
} // Main function to test quicksort

// Utility function to print the array
void print_array(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[] = {34, 7, 23, 32, 5, 62, 32, 32};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  print_array(arr, len);

  quick_sort(arr, len);

  printf("Sorted array:\n");
  print_array(arr, len);

  return 0;
}