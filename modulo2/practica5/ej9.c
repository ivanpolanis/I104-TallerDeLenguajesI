#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct {
  char name[20], surname[20];
  int titles, rank;
  float wealth;
} player;

void readPlayers(FILE *);
void getBestPlayer();

int main(){
  FILE *f = fopen("recursos/players.dat", "wb");
  if (f == NULL)
  {
    printf("An error has ocurred.");
    return 1;
  }
  readPlayers(f);
  fclose(f);
  getBestPlayer();
  return 0;
}

void readPlayers(FILE *f){
  player p;
  for (int i = 0; i < N; i++)
  {
    printf("Enter player name: ");
    scanf("%s", p.name);
    printf("Enter player last name: ");
    scanf("%s", p.surname);
    printf("Enter number of titles: ");
    scanf("%d", &p.titles);
    printf("Enter player rank: ");
    scanf("%d", &p.rank);
    printf("Enter player wealth: ");
    scanf("%f", &p.wealth);
    fwrite(&p, sizeof(player), 1, f);
  }
}

void getBestPlayer(){
  FILE *f = fopen("recursos/players.dat", "rb");
  player p, mostRanked, mostTitles;
  mostRanked.rank = 1000;
  mostTitles.titles = 0;
  while (fread(&p, sizeof(player), 1, f) != 0)
  {
    if (p.rank < mostRanked.rank)
    {
      mostRanked = p;
    }
    if (p.titles > mostTitles.titles)
    {
      mostTitles = p;
    }
  }
  printf("Most ranked player: %s %s\n", mostRanked.name, mostRanked.surname);
  printf("Most titled player: %s %s\n", mostTitles.name, mostTitles.surname);
  fclose(f);
}