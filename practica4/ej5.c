#include <stdio.h>
#include <stdlib.h>
#define N 100

char *reservar(char *p);
void inicializar(char *p);
void clear_buffer();
void printmm(char *p);

int main()
{
  char *p, car[10];
  p = reservar(p);
  inicializar(p);
  printmm(p);
  return 0;
}

char *reservar(char *p)
{
  p = (char *)malloc(N * sizeof(char));
  return p;
}

void inicializar(char *p)
{
  char str[10];
  for (int i = 0; i < (N / 10); i++)
  {
    printf("Ingrese una palabra: ");
    fgets(str, 10, stdin);
    for (int j = 0; j < 10; j++)
    {
      p[i + j] = str[j];
    }
    clear_buffer();
  }
}

void printmm(char *p)
{

  for (int i = 0; i < (N / 10); i++)
  {
    int mayus = 0, minus = 0;
    for (int j = 0; j < 10; j++)
    {
      if (p[j + i] >= 'a' && p[j + 1] <= 'z')
        minus++;
      if (p[j + i] >= 'A' && p[j + i] <= 'Z')
        mayus++;
    }
    printf("Las mayusculas son: %d\n", mayus);
    printf("Las minusculas son: %d\n", minus);
    printf("-------------------------------\n");
  }
}

void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}