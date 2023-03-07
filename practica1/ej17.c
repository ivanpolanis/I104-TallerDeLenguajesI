#include <stdio.h>
void minMax(int n, float *min, float *max){
  float aux;
  printf("Ingrese un numero: ");
  scanf("%f", &aux);
  *min = aux;
  *max = *min;
  for (int i = 1; i < n;i++){
    printf("Ingrese un numero: ");
    scanf("%f",&aux);
    if (aux < *min){
      *min = aux;
    } else if (aux > *max){
      *max = aux;
    }
  }
}
int main(){
  float min, max;
  int n;
  printf("Ingrese en numero de enteros a leer: ");
  scanf("%d", &n);
  minMax(n, &min, &max);
  printf("El minimo fue %.2f y el maximo %.2f.", min, max);
  return 0;
}