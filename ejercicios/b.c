#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cod_materia;
	int cod_alumno;
}inscripcion;

typedef struct{
	inscripcion dato;
	lista sig;
} lista;

void informar_inscripciones(lista l){
	while(l != NULL){
		printf("%d %d", l.dato.cod_materia, l.dato.cod_alumno);
		l = l.sig;		
	}
}

int main() {
  lista l;
  l.dato.cod_materia = 1;
  l.dato.cod_alumno = 2;
  l.sig = NULL;
  informar_inscripciones(l);
  return 0;
}