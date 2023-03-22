#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int array[50];
  for (int i = 0; i < 50; i++)
  {
    array[i] = rand();
  }

  int par = 0, impar = 0;
  for (int i = 0; i < 50; i++)
  {
    if (array[i++] % 2)
      impar++;
    if (!(array[i] % 2))
      par++;
  }
  printf("Impares: %d, pares: %d", impar, par);
  return 0;
}