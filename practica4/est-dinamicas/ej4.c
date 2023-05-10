#include <stdio.h>
#include <stdlib.h>

float *reserva(float *, int);
void inicializacion(float *, int);
float prom(float *, int);

int main(){
  float *p;
  int n;
  printf("Ingrese un numero por teclado: ");
  scanf("%d", &n);
  p = reserva(p, n);
  inicializacion(p, n);
  printf("El promedio es: %.2f", prom(p, n));
  return 0;
}

float *reserva(float *p, int n){
  p = (float *)malloc(n * sizeof(float));
  return p;
}

void inicializacion(float *p, int n){
  for (int i = 0; i < n; i++){
    float f;
    printf("Ingrese un numero: ");
    scanf("%f", &f);
    p[i] = f;
  }
}

float prom(float *p, int n){
  float promedio = 0;
  for (int i = 0; i < n; i++){
    promedio += p[i];
  }
  return promedio / n;
}