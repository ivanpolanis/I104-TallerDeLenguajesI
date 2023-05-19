#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *f = fopen("recursos/apuestas.txt", "r");
  int code;
  float amount, total = 0;
  if(f == NULL){
    printf("An error has ocurred.");
    return 1;
  }

  while(!feof(f)){
    fscanf(f, "%d|%f;", &code, &amount);
    total += amount;
  }

  printf("Total amount: %.2f", total);

  return 0;
}