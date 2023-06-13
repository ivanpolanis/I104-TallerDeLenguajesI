#include <stdio.h>
int main()
{
  int i;
  printf("a:\n");
  for (i = 0; i <= 11; i++)
    printf("%d\n", i);
  // Se imprimen los numeros del 0 al 11 inclusive.
  printf("b:\n");
  for (i = 0; i <= 11; ++i)
    printf("%d\n", i);
  // Se imprimen los numeros del 0 al 11 inclusive.
  printf("c:\n");
  for (i = 2; i <= 11; i += 2)
    printf("%d\n", i);
  // Se imprimen los numeros 2,4,6,8,10
  printf("d:\n");
  for (i = 1; i <= 11; i *= 2)
    printf("%d\n", i);
  // Se imprimen los numeros 1,2,4,8
  printf("e:\n");
  for (i = 11; i >= 1; i -= 2)
    printf("%d\n", i);
  // Se imprimen los numeros 11,9,7,5,3,1
  printf("f:\n");
  for (i = 11; i > 1; i = +1)
    printf("%d\n", i);
  // Se imprime 11
  return 0;
}