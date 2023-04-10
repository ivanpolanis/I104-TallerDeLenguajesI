#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
  int tipo;
  union
  {
    time_t time;
    char c[11];
  } fecha;
} Fecha;

int comparar(Fecha f1, Fecha f2);
int main()
{
  Fecha f1, f2;
  f1.tipo = 0;
  f1.fecha.time = time(NULL);
  f2.tipo = 1;
  strcpy(f2.fecha.c,"10-04-2022");
  printf("%d", comparar(f1, f2));
  return 0;
}

int comparar(Fecha f1, Fecha f2)
{
  if (f1.tipo && f2.tipo)
  {
    if (f1.tipo == 0)
      return f1.fecha.time == f2.fecha.time;
    else
      return !strcmp(f1.fecha.c, f2.fecha.c);
  }
  struct tm *struct_tm;
  char aux[11];
  if (f1.tipo == 0)
  {
    struct_tm = localtime(&f1.fecha.time);
    strftime(aux, sizeof(aux), "%d-%m-%Y", struct_tm);
    return !strcmp(aux, f2.fecha.c);
  }
  else
  {
    struct_tm = localtime(&f2.fecha.time);
    strftime(aux, sizeof(aux), "%d-%m-%Y", struct_tm);
    return !strcmp(aux, f1.fecha.c);
  }
}