#include <stdio.h>

// Esta estructura ocupa un total de 12 bytes, ya que un float ocupa 4 bytes y como hay variables de tipo float, suma un total de 12;
struct pun3D
{
  float x, y, z;
};

typedef struct pun3D punto3D;

int main(){
  // Ocupara un total de 48 bytes, ya que es un array de 4 elementos y el tipo punto3D ocupa 12.
  // Por lo que 12 bytes * 4 = 48 bytes;
  punto3D arr[4];
  printf("El tamanio de pun3D es %i\n", sizeof(struct pun3D));
  printf("El tamanio de punto3D es %i\n", sizeof(punto3D));
  printf("El tamanio del arr punto3D es %i", sizeof(arr));
  return 0;
}
