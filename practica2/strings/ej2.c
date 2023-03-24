#include <stdio.h>
#include <string.h>

int main(){
  char string[255];
  int counter = 0;
  do {
    printf("Ingrese una palabra: ");
    scanf("%s", string);
    if(string[strlen(string)-1]=='o')
      counter++;
  } while (strcmp(string, "XXX"));
  printf("%d", counter);
  return 0;
}