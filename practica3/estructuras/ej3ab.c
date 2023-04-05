#include <stdio.h>
#include <string.h>
#define N 3

struct direccion
{
  char calle[50];
  char ciudad[30];
  int codigo_postal;
  char pais[40];
};

struct alu
{
  char apellido[50];
  char nombre[50];
  char legajo[8];
  float promedio;
  struct direccion domicilio;
};

typedef struct alu alumno;

void inicializarDir(struct direccion *dir)
{
  printf("Ingrese la calle: ");
  scanf("%s", &(dir->calle));
  printf("Ingrese la ciudad: ");
  scanf("%s", &(dir->ciudad));
  printf("Ingrese el codigo postal: ");
  scanf("%d", &(dir->codigo_postal));
  printf("Ingrese el pais: ");
  scanf("%s", &(dir->pais));
}

void inicializarAlumno(alumno *alu)
{
  printf("Ingrese el apellido del alumno: ");
  scanf("%s", &(alu->apellido));
  printf("Ingrese el nombre del alumno: ");
  scanf("%s", &(alu->nombre));
  printf("Ingrese el legajo: ");
  scanf("%s", &(alu->legajo));
  printf("Ingrese el promedio: ");
  scanf("%f", &(alu->promedio));
  inicializarDir(&(alu->domicilio));
}

int main()
{
  alumno arr[N];

  for (int i = 0; i < N; i++)
  {
    inicializarAlumno(&arr[i]);
  }

  alumno mejorProm;
  mejorProm.promedio = 0;

  for (int i = 0; i < N; i++)
  {
    if (arr[i].promedio > mejorProm.promedio)
    {
      mejorProm.promedio = arr[i].promedio;
      strcpy(mejorProm.apellido, arr[i].apellido);
      strcpy(mejorProm.nombre, arr[i].nombre);
    }
  }

  printf("El alumno con mejor promedio es %s %s", mejorProm.apellido, mejorProm.nombre);

}