#include <stdio.h>
unsigned long int factorialIterativo(int n)
{
  unsigned long int fact = 1;
  while (n > 1)
  {
    fact *= n;
    n--;
  }
  return fact;
}
unsigned long int factorialRecursivo(unsigned long int n)
{
  if (n < 2)
    return 1;
  return n * factorialRecursivo(n - 1);
}
int main()
{
  printf("%lu", factorialIterativo(5));
  printf("%lu", factorialRecursivo(5));
  return 0;
}