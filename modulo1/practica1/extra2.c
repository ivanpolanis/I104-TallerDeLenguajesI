#include <stdio.h>
void imprimirBinIt(int n)
{
  int bin[32];
  int i = 0;
  while (n != 0)
  {
    bin[i] = n % 2;
    n /= 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--)
  {
    printf("%d", bin[j]);
  }
}

void imprimirBinRe(int n)
{
  if (n > 1)
  {
    imprimirBinRe(n / 2);
    printf("%d", n % 2);
  }
  else
    printf("%d", n);
}

int main()
{
  imprimirBinIt(126);
  printf("\n");
  imprimirBinRe(126);
  return 0;
}