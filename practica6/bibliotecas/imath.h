#ifndef IMATH_H
#define IMATH_H

int potencia(int x, int y)
{
  int i, pot = 1;
  for (i = 0; i < y; i++)
  {
    pot *= x;
  }
  return pot;
}

int cuadrado(int x)
{
  return x * x;
}

int cubo(int x)
{
  return x * x * x;
}

int absoluto(int x)
{
  return (x < 0) ? -x : x;
}

int factorial(int x)
{
  int i, fact = 1;
  for (i = 1; i <= x; i++)
  {
    fact *= i;
  }
  return fact;
}

int sumatoria(int i){
  int sum = 0;
  for (int j = 1; j <= i; j++)
  {
    sum += j;
  }
  return sum;
}

int multiplo(int x, int y){
  return (x % y == 0) ? 1 : 0;
}

int divisor(int x, int y){
  return (y % x == 0) ? 1 : 0;
}

int par(int i){
  return (i % 2 == 0) ? 1 : 0;
}

int impar(int i){
  return (i % 2 != 0) ? 1 : 0;
}

#endif