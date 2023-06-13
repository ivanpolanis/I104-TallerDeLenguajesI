#include <stdio.h>

int main()
{
  int arr[10] = {0};
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (n < 0)
    n *= -1;

  while (n > 0)
  {
    arr[n % 10]++;
    n /= 10;
  }

  for (int i = 0; i < 10; i++)
    printf("%d : %d\n",i, arr[i]);
  return 0;
}