#include <stdio.h>
#define COL 3
#define ROW 3

void escalar(int arr[ROW][COL], int n)
{
  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
      arr[i][j] *= n;
}

int main()
{
  int arr[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  escalar(arr, 3);

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }

  return 0;
}