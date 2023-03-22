#include <stdio.h>
#define ROW 3
#define COL 3

void sumaMatrices(int arr1[ROW][COL], int arr2[ROW][COL], int res[ROW][COL])
{
  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
      res[i][j] = arr1[i][j] + arr2[i][j];
}

int main()
{
  int arr1[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int arr2[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int res[ROW][COL];

  sumaMatrices(arr1, arr2, res);

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
      printf("%d ", res[i][j]);
    printf("\n");
  }
  return 0;
}