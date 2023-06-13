#include <stdio.h>

void a(float arr[], float *prom,float *max, float *min,size_t size){
  *max = arr[0];
  *min = arr[0];
  *prom = 0;

  for (int i = 1; i < size;i++){
    if(arr[i]>*max)
      *max = arr[i];
    if(arr[i]<*min)
      *min=arr[i];
    *prom += arr[i];
  }
  *prom /= size;
}

int main()
{
  float arr[] = {2.3, 4.5, 2.0, 12.3};
  size_t size = sizeof(arr) / sizeof(float);
  float prom, max, min;
  a(arr, &prom, &max, &min, size);
  printf("Prom: %.2f \nMin: %.2f \nMax: %.2f", prom, min, max);
  return 0;
}