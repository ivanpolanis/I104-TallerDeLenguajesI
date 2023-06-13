#include <stdio.h>
int main()
{
  int vector[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int i;
  int *p = vector;
  for (i = 0; i < 10; i++)
  {
    *p += 3;
    printf("vector[%d] = %d \n", i, *p);
    p++;
  }
  return 0;
}
//a) El programa imprime los valores del vector incrementados en 3.
//b) El vector se ve modificado ya que se incrementa el valor al que apunta el puntero. Si, es correcto.
//c) Si se cambia la linea 9 por vector[i] += 3, el programa funciona igual.
//d) Funcionaria igual.
//e) Se modificaria el vector cada dos posiciones y comenzaria a modificar los valores de memoria de otras variables.