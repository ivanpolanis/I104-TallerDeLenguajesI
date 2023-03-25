#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void upperStr(char *string)
{
  char *ptr = string;
  while (*ptr != '\0')
  {
    *ptr += 32;
    ptr++;
  }
}

void lowerStr(char *string)
{
  char *ptr = string;
  while (*ptr != '\0')
  {
    *ptr -= 32;
    ptr++;
  }
}

void numToStr(int n, char *string)
{
  char *ptr = string;
  int longitud = n == 0 ? 1 : (int)(log10(abs(n)) + 1);

  if (n < 0)
  {
    *ptr++ = '-';
    n = -n;
  }

  ptr += longitud;
  *ptr = '\0';
  ptr--;

  while (n != 0)
  {
    *ptr = n % 10 + '0';
    n /= 10;
    ptr--;
  }
}

char *numToText(int n, char *string)
{
  char *nums[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "diecinueve"};
  char *teens[] = {"", "", "treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};

  if (n<0 || n>99){
    strcpy(string, "Numero fuera de rango");
    return string;
  }

  if(n < 20){
    strcpy(string, nums[n]);
  } else if(n<30){
    sprintf(string, "veinti%s%s", nums[n%10]);
  } else{
    sprintf(string, "%s y %s", teens[(n / 10) - 1], nums[n % 10]);
  }
  return string;
}

int main()
{
  char string[100];
  numToText(95, string);
  printf("%s", string);
  return 0;
}