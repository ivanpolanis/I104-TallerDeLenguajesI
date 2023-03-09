#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tirarDados()
{
  return 2 + (rand() % 6) + (rand() % 6);
}

int main()
{
  srand(time(NULL));
  while (1)
  {
    int n = tirarDados();
    if (n == 11 || n == 7){
      printf("El jugador saco %d y gano.\n", n);
      break;}
    if(n==2 || n ==12){
      printf("El jugador saco %d y perdio.\n");
      break;
    }
    printf("El jugador saco %d y debe seguir jugando.\n", n);
  }
  return 0;
}