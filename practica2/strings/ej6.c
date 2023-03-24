#include <stdio.h>
#include <string.h>

int main()
{
  char string[255];
  int letras[26] = {0};

  printf("Introduzca una palabra: ");
  scanf("%s", string);

  for (int i = 0; i < strlen(string); i++)
    letras[string[i] - 'a']++;

  for (int i = 0; i < 26; i++)
  {
    if(letras[i]>0)
      printf("La letra %c aparece %d veces.\n", 'a' + i, letras[i]);
  }
  return 0;
}