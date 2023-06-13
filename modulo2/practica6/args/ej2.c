#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc != 5){
    printf("Four numbers are necessary.", argv[0]);
    return 1;
  }
  float prom = (atof(argv[1]) + atof(argv[2]) + atof(argv[3]) + atof(argv[4])) / 4;
  printf("The average is: %f", prom);
}