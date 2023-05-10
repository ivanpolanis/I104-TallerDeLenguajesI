#include <stdio.h>
#include <stdlib.h>

int *reserva(int*,int);
void inicializar();
int maximo(int *, int);

int main(){
  int *p;
  int n;
  printf("Ingrese un numero: ");
  scanf("%d", &n);
  p = reserva(p,n);
  inicializar(p, n);
  maximo(p, n);
  printf("El maximo es: %d", maximo(p, n));
  return 0;
}

int* reserva(int *p,int n){
  p = (int *)malloc(n * sizeof(int));
  return p;
}

void inicializar(int *p, int n){
  for (int i = 0; i < n; i++)
    p[i] = rand() % 100;
}

int maximo(int *p, int n){
  int max = -1;
  for (int i = 0; i < n; i++){
    if (p[i]> max)
      max = p[i];
  }
  return max;
}