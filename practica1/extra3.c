#include <stdio.h>
#include <math.h>
double calcularPi(int n)
{
  double pi = 3;
  for (int i = 0; i < n; i++)
  {
    pi += 4 * (pow(-1, i) / (pow(2 * i + 3, 3) - (2 * i + 3)));
  }
  return pi;
}

int main(){
  printf("%lf", calcularPi(1000));
  return 0;
}