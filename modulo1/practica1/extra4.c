#include <stdio.h>
#include <math.h>
int sumarDigitos(int n){
  n = abs(n);
  int aux = 0;
  if (n<10)
    return n;
  while(n != 0){
    aux += n % 10;
    n /= 10;
  }
  return sumarDigitos(aux);
}

int main(){
  printf("%d", sumarDigitos(305));
}