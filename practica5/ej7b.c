#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 256
int main(){
  FILE *read = fopen("recursos/apuestas.txt", "r");
  FILE *write = fopen("recursos/copia.txt", "w");
  char line[BUFFER_SIZE];
  while(fgets(line,BUFFER_SIZE,read) != NULL){
    fputs(line, write);
  }
  fclose(read);
  fclose(write);
  return 0;
}