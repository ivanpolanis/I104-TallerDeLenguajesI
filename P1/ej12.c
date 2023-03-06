#include <stdio.h>
#include <math.h>
int main()
{
  for (int i = 1; i <= 10; i++)
  {
    printf("La raiz cuadrada de %d es: %.2lf. Y su cuadrado es: %d\n", i, sqrt(i), i * i);
    // Sabiendo que queremos saber el cuadrado de un numero, me parece inecesario hacer un llamado a la funcion pow. Ademas la misma devuelve un double y no un entero, que no nos interesa porque los cuadrados de los numeros enteros, son siempre enteros.
  }
}