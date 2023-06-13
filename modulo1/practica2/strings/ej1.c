#include <stdio.h>
#include <string.h>

int main()
{
  char string[255];
  int counter;
  do
  {
    printf("Introduzca una palabra: ");
    scanf("%s", string);
    if (strlen(string) == 5)
      counter++;
  } while (strcmp(string, "ZZZ"));
  printf("%d", counter);
  return 0;
}