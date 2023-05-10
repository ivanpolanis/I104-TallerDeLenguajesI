#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *allocateMemory(int);
void init(int *, int);
void printMatrix(int *, int);
void freeMemory(int *);

int main()
{
  int base, cols;
  printf("Enter the base: ");
  scanf("%d", &base);
  int *matrix = allocateMemory(base);
  init(matrix, base);
  printMatrix(matrix, base);
  freeMemory(matrix);
  return 0;
}

int *allocateMemory(int base)
{
  int *matrix = (int *)calloc(base * (base + 1) / 2, sizeof(int));
  return matrix;
}

void init(int *matrix, int base)
{
  srand(time(NULL));
  for (int i = 0; i < base; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      *(matrix + i + j) = rand() % 20;
    }
  }
}

void printMatrix(int *matrix, int base)
{
  for (int i = 0; i < base; i++)
  {
    for (int j = 0; j < base; j++)
    {
      if (j <= i)
        printf("%3.d ", *(matrix + i + j));
      else
        printf(" 0 ", 0);
    }
    printf("\n");
  }
}

void freeMemory(int *matrix)
{
  free(matrix);
}