#include <stdio.h>

int strlength(char *string){
  char *puntero = string;
  int counter = 0;
  while (*puntero != '\0')
  {
    counter++;
    puntero++;
  }
  return counter;
}

int main(){
  char string[255];
  printf("Ingrese una palabra: ");
  scanf("%s", string);
  printf("%d", strlength(string));
  return 0;
}