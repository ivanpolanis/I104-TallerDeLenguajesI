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
  int pos = 0;
  for (int i = 0; i < base; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if(j == 0 || j == i){
        *(matrix + i + pos + j) = 1;
      } else{
        *(matrix + i + pos + j) = *(matrix + pos + j) + *(matrix + pos - 1 + j);
      }
    }
    pos += i;
  }
}

void printMatrix(int *matrix, int base)
{
  int pos = 0;
  for (int i = 0; i < base; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      printf("%d ", *(matrix + i + j + pos));
    }
    printf("\n");
    pos += i;
  }
}

void freeMemory(int *matrix)
{
  free(matrix);
}