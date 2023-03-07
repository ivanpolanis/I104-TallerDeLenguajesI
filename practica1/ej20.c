#include <stdio.h>
int damePar(){
  static int n = -2;
  return n += 2;
}
int main(){
  int n;
  printf("Ingrese el numero de pares: ");
  scanf("%d",&n);
  for (int i = 0; i < n;i++){
    printf("%d ", damePar());
  }
  return 0;
}