#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocateMemory(int, int);
void init(int **, int, int);
void printMultiplesOfThree(int **, int, int);
void freeMemory(int **, int);

int main(){
  int rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);
  int **matrix = allocateMemory(rows, cols);
  init(matrix, rows, cols);
  printMultiplesOfThree(matrix, rows, cols);
  freeMemory(matrix, rows);
  return 0;
}

int **allocateMemory(int rows, int cols){
  int **matrix = (int **)calloc(rows, sizeof(int*));
  for (int i = 0; i < rows; i++){
    matrix[i] = (int *)calloc(cols, sizeof(int));
  }
  return matrix;
}

void init(int **matrix, int rows, int cols){
  srand(time(NULL));
  for(int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      matrix[i][j] = rand() % 100;
    }
  }
}

void printMultiplesOfThree(int **matrix, int rows, int cols){
  for (int i = 0; i < rows; i ++){
    for (int j = 0; j<cols;j++){
      if(!(matrix[i][j] % 3))
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void freeMemory(int **matrix, int rows){
  for (int i = 0; i < rows; i ++){
    free(matrix[i]);
  }
  free(matrix);
}