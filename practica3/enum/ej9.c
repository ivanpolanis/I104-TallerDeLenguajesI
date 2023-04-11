#include <stdio.h>

typedef enum
{
  DOMINGO,
  LUNES,
  MARTES,
  MIERCOLES,
  JUEVES,
  VIERNES,
  SABADO
} Dias;

void imprimirDias()
{
  char *semana[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

  printf("Los dias de la semana son: ");
  for (Dias i = DOMINGO; i <= SABADO; i++)
  {
    printf("%s ", semana[i]);
  }
}

int main () {
  imprimirDias();
  return 0;
}