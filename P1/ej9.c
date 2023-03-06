#include <stdio.h>
int main()
{
  int a, b;
  char c;
  printf("Ingrese el primer numero: ");
  scanf("%d", &a);
  printf("Ingrese el segundo numero: ");
  scanf(" %d", &b);
  printf("Ingrese la operacion(+,-,/,x): ");
  scanf(" %d", &c);
  switch (c)
  {
  case '+':
    printf("El resultado de la suma es: %d\n", a + b);
    break;
  case '-':
    printf("El resultado de la resta es: %d\n", a - b);
    break;
  case '/':
    printf("El resultado de la division entera es: %d\n", a / b);
    break;
  case 'x':
    printf("El resultado de la multiplicacion es: %d\n", a * b);
    break;
  default:
    printf("Ingreso un caracter no valido");
    break;
  }
  return 0;
}