#include <stdio.h>
#include <string.h>
#define PI 3.1415

enum figuras { Cuadrado, Triangulo, Circulo};

struct cuad{
	float lado;
};

struct tri{
	float cateto1, cateto2;
};

struct circ{
	float radio;
};

typedef struct fig{
	int tipo;
	char color[7];
	union{
		struct cuad cuadrado;
		struct tri triangulo;
		struct circ circulo;
  } figura;
} Figura;

void imprimirFigura(Figura f){
	if(f.tipo == Cuadrado){
			printf("Figura: cuadrado | Color: %s | Area: %.2f",f.color, f.figura.cuadrado.lado*f.figura.cuadrado.lado);
}	else if(f.tipo == Triangulo) {
			printf("Figura: triangulo | Color: %s | Area: %.2f",f.color, f.figura.triangulo.cateto1*f.figura.triangulo.cateto2/2);
}	else {
			printf("Figura: circulo | Color: %s | Area: %.2f",f.color, PI*f.figura.circulo.radio*f.figura.circulo.radio);
}
}

int main(){

  Figura f1;

  f1.tipo = Cuadrado;
  f1.figura.cuadrado.lado = 5;
  strcpy(f1.color, "rojo");

  imprimirFigura(f1);
	
	return 0;
}