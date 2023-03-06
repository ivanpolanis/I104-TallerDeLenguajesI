#include <stdio.h>
int main()
{
  // a.
  int edad;
  scanf("%d", &edad);
  if (edad >= 40)
    printf("Tiene %d años o mas\n", 40);
  else
    printf("Tiene menos de %d años\n", 40);

  // b.
  int total,
      x = 1;
  while (x <= 10)
  {
    total += x;
    ++x;
  }
  printf("Total = %d\n", total);

  // c.
  int valor;
  scanf(" %d", &valor);
  switch (valor % 2)
  {
  case 0:
    printf("El valor es par");
    break;
  case 1:
    printf("El valor es impar");
  }

  // d.
  int y, z;
  scanf(" %d", &y);
  scanf(" %d", &z);
  printf("y+z=%d", y + z);

  return 0;
}