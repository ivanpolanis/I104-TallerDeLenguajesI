#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int day, precipitation;
} Day;

int main()
{
  FILE *f = fopen("recursos/precipitaciones.txt", "r");
  Day aux, max={0,0};

  if (f == NULL)
  {
    printf("An error has ocurred.");
    return 1;
  }

  int i = 1;

  while(!feof(f)){
    fscanf(f, "%d-", &aux.precipitation);
    aux.day = i;
    if(aux.precipitation > max.precipitation){
      max.precipitation = aux.precipitation;
      max.day = aux.day;
    }
    i++;
  }

  fclose(f);

  printf("The day with the highest precipitation is day %d, with %d mm.\n", max.day, max.precipitation);

  return 0;
}