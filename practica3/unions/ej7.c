#include <stdio.h>

typedef struct {
  char ap[50];
  char nom[50];
  char leg[10];
  int ext;
  union
  {
    long unsigned dni;
    char pas[20];
  } ID;
} alumno;

int main(){
  alumno al;

  printf("Ingrese el apellido: ");
  scanf("%s", al.ap);
  printf("Ingrese el nombre: ");
  scanf("%s", al.nom);
  printf("Ingrese el legajo: ");
  scanf("%s", al.leg);
  printf("Ingrese si es extranjero o no (1=si/0=no): ");
  scanf("%d", &al.ext);
  if (!(al.ext))
    {
    printf("Ingrese el DNI: ");
    scanf("%ld", &al.ID.dni);
    printf("%s %s %s - %ld", al.ap, al.nom, al.leg, al.ID.dni);
    }
  else{
    printf("Ingrese el pasaporte: ");
    scanf("%s", al.ID.pas);
    printf("%s %s %s - %s", al.ap, al.nom, al.leg, al.ID.pas);
  }


  return 0;
}