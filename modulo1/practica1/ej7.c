#include <stdio.h>
int main(){
  char a, b;
  printf("Ingrese el primer caracter: ");
  scanf("%c", &a);
  printf("Se leyo el caracter: %c\n", a);
  printf("Ingrese el segundo caracter: ");
  scanf(" %c", &b); //Se agrega un espacio delante de %c para descartar el caracter de salto de linea que esta almacenado en el buffer
  printf("Se leyo el caracter %c\n", b);
  return 0;
}