#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *allocateMemory(int);
void initArr(double *, int);
double average(double *, int);
void freeMemory(double *);

int main(){
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  double *arr = allocateMemory(n);
  initArr(arr, n);
  printf("The average is: %.2f", average(arr, n));
  freeMemory(arr);
  return 0;
}

double *allocateMemory(int size){
  double *arr = (double *)malloc(size * sizeof(double));
  return arr;
}

void initArr(double *arr, int size){
  srand(time(NULL));
  for (int i = 0; i < size; i++){
    *(arr + i) = rand() % 100;
  }
}

double average(double *arr, int size){
  double avg = 0;
  for (int i = 0; i < size; i++)
    avg += *(arr + i);
  return avg/size;
}

void freeMemory(double *arr){
  free(arr);
}