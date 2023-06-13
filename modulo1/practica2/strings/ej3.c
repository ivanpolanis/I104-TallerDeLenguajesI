#include <stdio.h>
#include <string.h>

char* reemplazar(char string[], char a, char b){
  char *puntero = string;
  while(*string!='\0'){
    if(*string==a)
      *string = b;
    string++;
  }
  return puntero;
}

int main(){
  char string[255];
  char a, b;
  printf("Ingrese una palabra: ");
  scanf("%s", string);
  printf("Ingrese el caracter a reemplazar: ");
  scanf(" %c", &a);
  printf("Ingrese el caracter por el que reemplazar: ");
  scanf(" %c", &b);
  printf("%s", reemplazar(string, a, b));
  return 0;
}