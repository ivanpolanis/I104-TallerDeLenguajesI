#include <stdio.h>
int reverseNumber(int n)
{
  int aux = 0;
  while (n != 0)
  {
    aux = aux * 10 + n % 10;
    n /= 10;
  }
  return aux;
}
int main()
{
  int n;
  printf("Ingrese un numero: ");
  scanf("%d", &n);
  printf("El numero invertido es: %d.\n", reverseNumber(n));
  return 0;
}