#include <stdio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

void invertirArr(int arr[], size_t size)
{
  int left = 0;
  int right = size - 1;
  while (left<right){
    swap(&arr[left], &arr[right]);
    left++;
    right--;
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  size_t size = sizeof(arr) / sizeof(int);
  invertirArr(arr, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}