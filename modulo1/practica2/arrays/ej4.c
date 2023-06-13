#include <stdio.h>
#define ROW 3
#define COL 3

void imprimirMatriz(int arr[ROW][COL])
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
      printf("%d ", arr[j][i]);
    printf("\n");
  }
}

int main()
{
  int arr[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  imprimirMatriz(arr);
  return 0;
}