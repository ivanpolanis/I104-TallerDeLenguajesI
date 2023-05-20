#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *read = fopen("recursos/apuestas.txt", "r");
  FILE *write = fopen("recursos/copia.txt", "w");
  int c;
  do{
    c = fgetc(read);
    if(feof(read))
      break;
    fputc(c, write);
  } while (1);
  fclose(read);
  fclose(write);
  return 0;
}