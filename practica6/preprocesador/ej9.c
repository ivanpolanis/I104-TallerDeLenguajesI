#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1
#define SIZE 1000

void fillArray(int *arr, int size);
int findElement(int *arr, int size, int element);

int main(){
  int arr[SIZE];
  fillArray(arr, SIZE);
  int element = 0;
  element = findElement(arr, SIZE, 32);
  return 0;
}

void fillArray(int *arr, int size){
  srand(time(NULL));
  for(int i = 0; i < size; i++){
    arr[i] = rand() % 1000;
  }
}

int findElement(int *arr, int size, int element){
  for(int i = 0; i < size; i++){
    if(arr[i] == element){
      #if DEBUG
      printf("Array was accessed %d times.", i + 1);
      #endif
      return i;
    }
  }
  return -1;
}