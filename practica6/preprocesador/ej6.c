#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define AREACIRCULO(r) (PI * (r) * (r))

int main(){
  srand(time(NULL));
  for (int i = 0; i < 10; i++){
    int r = rand() % 10;
    printf("r=%d, area=%f\n", r, AREACIRCULO(r));
  }
}
