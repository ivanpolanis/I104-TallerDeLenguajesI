#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *txt = fopen("recursos/numeros.txt", "w");
  FILE *bin = fopen("recursos/numeros.dat", "wb");
  if (bin == NULL || txt == NULL)
  {
    printf("An error has ocurred.");
    return 1;
  }
  int n;
  do
  {
    printf("Enter a number: ");
    scanf("%d", &n);
    fprintf(txt, "%d", n);
    fwrite(&n, sizeof(int), 1, bin);
  } while (n != 0);
  fclose(txt);
  fclose(bin);
  return 0;
}