#include <stdio.h>

char *strcopy(char *str1, char *str2)
{
  char *aux1 = str1;
  char *aux2 = str2;
  while(*aux2!='\0')
  {
    *aux1 = *aux2;
    aux1++;
    aux2++;
  }
  *aux1 = *aux2;
  return str1;
}

int main(){
  char string1[255];
  char string2[255];
  printf("Ingrese una palabra: ");
  scanf("%s", string1);
  printf("Ingrese otra palabra: ");
  scanf("%s", string2);
  printf("%s", strcopy(string1, string2));
  return 0;
}