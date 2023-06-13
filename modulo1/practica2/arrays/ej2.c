#include <stdio.h>
#include <stdlib.h>

float prom(float arr[], size_t size)
{
  float p = 0;
  for (int i = 0; i < size; i++)
  {
    p += arr[i];
  }
  return p / size;
}

float maxx(float arr[], size_t size)
{
  float m = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (m < arr[i])
      m = arr[i];
  }
  return m;
}

float minn(float arr[],size_t size)
{
  float m = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (m > arr[i])
      m = arr[i];
  }
  return m;
}

int main(){
  float arr[] = {2.3, 4.5, 2.0, 12.3};
  size_t size = sizeof(arr) / sizeof(float);
  printf("Prom: %.2f \nMin: %.2f \nMax: %.2f", prom(arr,size), minn(arr,size), maxx(arr,size));
  return 0;
}