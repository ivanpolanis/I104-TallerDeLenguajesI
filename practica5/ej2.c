#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

typedef struct
{
  int up, low, dig;
} CharCount;

void count(char *, CharCount *);

int main()
{
  FILE *f = fopen("recursos/prueba.txt", "r");
  CharCount counter = {0, 0, 0};
  char buffer[BUFFER_SIZE];
  if (f == NULL)
  {
    printf("\nAn error has ocurred.\n");
    return 1;
  }

  while (fgets(buffer, BUFFER_SIZE, f) != NULL)
  {
    count(buffer, &counter);
  }

  if (!feof(f))
  {
    printf("\nAn error has ocurred.\n");
    return 1;
  }

  printf("Up: %d; Low: %d; Dig: %d;\n", counter.up,counter.low,counter.dig);

  return 0;
}

void count(char *buffer, CharCount *counter)
{
  int i = 0;
  while (*(buffer + i) != '\n')
  {
    if (*(buffer + i) >= 'A' && *(buffer + i) <= 'Z')
      counter->up++;
    else if (*(buffer + i) >= 'a' && *(buffer + i) <= 'z')
      counter->low++;
    else if (*(buffer + i) >= '0' && *(buffer + i) <= '9')
      counter->dig++;
    i++;
  }
}