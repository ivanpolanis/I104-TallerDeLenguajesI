#include <string.h>
#include <stdio.h>

int main()
{
  char min[20] = "********************", palabra[20] = "";

  while (strcmp(palabra, "FIN"))
  {
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    if (strlen(palabra) <= strlen(min) && strcmp(palabra, "FIN"))
    {
      strcpy(min, palabra);
    }
  }
  printf("La palabra con menor longitud es: %s", min);
  return 0;
}