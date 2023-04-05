#include <stdio.h>
#include <string.h>

#define N_CARTAS 50

typedef struct
{
  char palo[10];
  int num;
} carta;

void inicializarMazo(carta mazo[])
{
  char palos[4][10] = {{"Basto"}, {"Copa"}, {"Espada"}, {"Oro"}};
  for (int i = 0; i < 4; i++)
  {
    printf("%s", palos[i]);
    for (int j = 1; j <= (N_CARTAS - 2) / 4; j++)
    {
      strcpy(mazo[(i *12) + j - 1].palo, palos[i]);
      mazo[(i *12) + j - 1].num = j;
    }
  }
  strcpy(mazo[48].palo, "Comodin");
  mazo[48].num = 0;
  strcpy(mazo[49].palo, "Comodin");
  mazo[49].num = 0;
}

void imprimirMazo(carta mazo[])
{
  printf("Mazo:\n");
  for (int i = 0; i < N_CARTAS; i++)
  {
    printf("I:%d ", i);
    if (mazo[i].num == 0)
      printf("%s ", mazo[i].palo);
    else
      printf("%s %d ", mazo[i].palo, mazo[i].num);
    if (i % 10 == 0 && i != 0)
      printf("\n");
  }
}

int main()
{
  carta mazo[N_CARTAS];

  // Imprimir el mazo
  inicializarMazo(mazo);
  imprimirMazo(mazo);
}