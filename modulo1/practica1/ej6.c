#include <stdio.h>
int main(){
  float km,miles;
  printf("Introduzca la distancia en km: ");
  scanf("%f", &km);
  miles = km / 1.61;
  printf("La distancia en millas es: %.2f\n", miles);
  return 0;
}