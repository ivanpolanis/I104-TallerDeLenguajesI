#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand(time(NULL));
  for (int i = 1; i <= 15;i++){
    printf("%d ", rand());
  }
  return 0;
}