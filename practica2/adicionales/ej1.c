#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarArray(int arr[], size_t size)
{
  srand(time(NULL));
  for (int i = 0; i < size; i++)
  {
    arr[i] = rand() % 100;
  }
}

void imprimir(int arr[], size_t size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
    swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int q = partition(arr, low, high);
    quicksort(arr, low, q - 1);
    quicksort(arr, q + 1, high);
  }
}

int main()
{
  int arr[25];
  inicializarArray(arr, 25);
  imprimir(arr, 25);
  printf("\n");
  quicksort(arr, 0, 24);
  imprimir(arr, 25);
  return 0;
}