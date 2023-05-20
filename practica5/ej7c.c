#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 256
int main(){
  FILE *read = fopen("recursos/apuestas.txt", "r");
  FILE *write = fopen("recursos/copia.txt", "w");
  char buffer[BUFFER_SIZE];
  size_t bytesRead;
  while((bytesRead = fread(buffer,sizeof(char),BUFFER_SIZE,read))> 0){
    fwrite(buffer, sizeof(char), bytesRead, write);
  }
  fclose(read);
  fclose(write);
  return 0;
}