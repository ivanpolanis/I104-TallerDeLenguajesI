/*
La estructura de control for esta divida en 4 partes
for(parte1;parte2;parte4){
  parte3
}
La parte 1, es donde se inicializan las variables.
La parte 2, es la encargada de verificar que se cumplen las condiciones luego de cada ciclo del for.
La parte 3, es el código escrito dentro del mismo ciclo.
La parte 4, se utiliza para hacer operaciones que modifiquen el valor de las variables que verifican en la parte 2.
Por ejemplo:
*/
#include <stdio.h>
int main()
{
  for (int i = 1; i < 10; i++)
  {
    printf("%d\n", i);
  }
}