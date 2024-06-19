#include <stdio.h>
#include <math.h>

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n"); // For a newline after printing the array
}
int main()
{

  int arr[] = {1, 24, 612, 621, 6, 26, 1234, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 3;

  bubble_sort(arr, size);
  printArray(arr, size);

  // printf() displays the string inside quotation
  return 0;
}


// void bubble_sort(int arr[], int size)
// {
//   for (int i = 0; i < size; i++)
//   {
//     for (int j = 0; j < size - 1 - i; j++)
//     {
//       if (arr[j] > arr[j + 1])
//       {
//         int tmp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = tmp;
//       }
//     }
//   }
// };

// int binary_search(int arr[], int size, int val)
// {
//   int low = 0;
//   int high = size;
//   while (low < high)
//   {
//     int mid = low + (high - low) / 2;
//     int v = arr[mid];
//     if (v == val)
//     {
//       return mid;
//     }
//     else if (val > v)
//     {
//       low = mid + 1;
//     }
//     else
//     {
//       high = mid;
//     }
//   }
//   return -1;
// }

// int linear_search(int arr[], int size, int target)
// {
//   for (int i = 0; i < size; i++)
//   {
//     if (arr[i] == target)
//     {
//       return i;
//     }
//   }

//   return -1;
// };

// int two_crystal_balls(bool breaks[], int size)
// {
//   int jumpAmount = floor(sqrt(size));

//   int i = jumpAmount;
//   while (i < size && !breaks[i])
//   {
//     i += jumpAmount;
//   }

//   i -= jumpAmount;
//   for (int j = 0; j < jumpAmount && i < size; j++, i++)
//   {
//     if (breaks[j])
//     {
//       return i;
//     }
//   }
//   return -1;
// }