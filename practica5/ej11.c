#include <stdio.h>
#include <stdlib.h>

long getFileSize(FILE *file);

int main(){
  FILE *f = fopen("recursos/players.dat", "rb");
  if (f == NULL)
  {
    printf("An error has ocurred.");
    return 1;
  }
  long size = getFileSize(f);
  printf("File size: %ld bytes\n", size);
  fclose(f);
  return 0;
}

long getFileSize(FILE *file) {
    long size;

    // Desplaza el puntero de archivo al final
    fseek(file, 0, SEEK_END);

    // Obtiene la posición actual del puntero de archivo, que corresponde al tamaño del archivo
    size = ftell(file);

    // Vuelve a colocar el puntero de archivo al principio
    rewind(file);

    return size;
}