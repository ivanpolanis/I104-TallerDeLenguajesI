#include <stdio.h>

struct alu {
 char apellido[50];
 char nombre[50];
 char legajo[8];
};

typedef struct alu alumno;

void inicializarAlu(alumno al);

int main(){
	alumno alumnos[10];
	for(int i = 0; i < 10; i ++){
	inicializarAlu(&alumnos[i]);
	}
	for(int i = 0; i < 10; i++){
	printf("Apellido y nombre: %s, %s | Legajo: %s",alumnos[i].apellido,alumnos[i].nombre,alumnos[i].legajo);
	}
	return 0;
}

void inicializarAlu(alumno *al){
	printf("Ingrese el nombre del alumno: ");
	scanf("%s",&(al->nombre));
	printf("Ingrese el apellido del alumno: ");
	scanf("%s",&(al->apellido));
	printf("Ingrese el legajo: ");
	scanf("%s",&(al->legajo));
}