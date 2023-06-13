#include <stdio.h>
#include <stdlib.h>

void getDivisors(int *, int *, int);
void printArr(int *, int);

int main()
{
  int *arr = (int *)malloc(sizeof(int));
  *arr = 1;
  int size = 1;
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  getDivisors(arr, &size, n);
  printArr(arr, size);
  return 0;
}

void getDivisors(int *arr, int *size, int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!(n % i))
    {
      *size += 1;
      arr = (int *)realloc(arr, sizeof(int) * (*size));
      *(arr + (*size) - 1) = i;
    }
  }
}

void printArr(int *arr, int size)
{
  for (int i = 0; i < size; i++){
    if(i== size-1){
      printf("%d", *(arr + i));
    } else {
      printf("%d->", *(arr + i));
    }
  }
}