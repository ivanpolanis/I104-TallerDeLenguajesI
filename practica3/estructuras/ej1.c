#include <stdio.h>
#include <stdlib.h>

#define N 3

struct rectangulo {
  float base;
  float altura;
};

void inicializarRectangulo(struct rectangulo* rect){
  printf("Ingrese la altura: ");
  scanf("%f", &(rect->altura));
  printf("Ingrese la base: ");
  scanf("%f", &(rect->base));
}

float area(struct rectangulo rect){
  return rect.altura * rect.base;
}

int main(){
  struct rectangulo arr[N];
  for(int i = 0; i < N; i++){
    inicializarRectangulo(&arr[i]);
  }
  float min = area(arr[0]);
  int rect = 0;
  for(int i = 1; i < N; i++){
    if(area(arr[i]) < min){
      min = area(arr[i]);
      rect = i;
    }
  }
  printf("El rectangulo de menor area es el %d", rect+1);
  return 0;
}