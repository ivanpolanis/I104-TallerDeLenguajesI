#include <stdio.h>
#define CANT_DATOS 10

// Esta funcion recorre un array a traves de un indice i y multiplica cada elemento por 0.5
void opcion1(int datos[])
{
  int i;
  for (i = 0; i < CANT_DATOS; i++)
  {
    datos[i] = datos[i] * 0.5;
  }
}

// Esta función recorre un array utilizando un puntero a memoria y divide los datos por 2.
void opcion2(int *datos)
{
  int i;
  for (i = 0; i < CANT_DATOS; i++)
  {
    (*datos++) = (*datos) / 2;
  }
}

// Esta funcion recorre un array utilizando un puntero a memoria y divide por 2. A diferencia de la opción 2, se incrementa donde esta apuntando una vez que se cumple con un ciclo del for.
void opcion3(int *datos)
{
  int i;
  for (i = 0; i < CANT_DATOS; i++, datos++)
  {
    *datos = *datos * 0.5;
  }
}

// Idem opcion 2
void opcion4(int datos[])
{
  int i;
  for (i = 0; i < CANT_DATOS; i++)
  {
    *datos++ = *datos / 2;
  }
}

// Reccorre un array utilizando un puntero y divide por dos al siguiente elemento y se lo asigna al anterior. En la ultima iteracion se divide por dos un elemento que no existe. Basura
void opcion5(int datos[])
{
  int i;
  for (i = 0; i < CANT_DATOS; i++, datos--)
  {
    *datos++ = *datos++ * 0.5;
  }
}

void opcion6(int *datos)
{
  int i;
  for (i = 0; i < CANT_DATOS; i++)
  {
    *datos = *datos++ * 0.5;
  }
}

// idem opcion 1
void opcion7(int datos[])
{
  int i;
  for (i = 0; i < CANT_DATOS; i++)
  {
    datos[i] = *(datos + i) * 0.5;
  }
}

// idem opcion 1
void opcion8(int *datos)
{
  int i;
  for (i = 0; i < CANT_DATOS; i++)
  {
    *(datos + i) = datos[i] / 2;
  }
}

int main()
{
  int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  opcion8(arr);
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);

  return 0;
}