#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct {
  char name[20], surname[20];
  int titles, rank;
  float wealth;
} player;

void readFile();
void readPlayer(char name[20], char surname[20], int *rank);
int updateRank(FILE *f, char name[20], char surname[20], int newRank);

int main(){
  readFile();
  FILE *f = fopen("recursos/players.dat", "rb+");
  if (f == NULL)
  {
    printf("An error has ocurred.");
    return 1;
  }
  char name[20], surname[20];
  int newRank;
  readPlayer(name, surname, &newRank);
  while(strcmp(name,"ZZZ")!=0){
    if (updateRank(f, name, surname, newRank) == 0)
    {
      printf("Player not found.\n");
    }
    readPlayer(name, surname, &newRank);
  }
  fclose(f);
  readFile();
  return 0;
}

void readFile(){
  FILE *f = fopen("recursos/players.dat", "rb");
  player p;
  while (fread(&p, sizeof(player), 1, f) != 0)
  {
    printf("%s %s %d %d %.2f\n", p.name, p.surname, p.titles, p.rank, p.wealth);
  }
  fclose(f);
}

int updateRank(FILE *f, char name[20],char surname[20], int newRank){
  player p;
  while (fread(&p, sizeof(player), 1, f) != 0)
  {
    if (strcmp(p.name, name) == 0 && strcmp(p.surname, surname) == 0)
    {
      p.rank = newRank;
      fseek(f, -sizeof(player), SEEK_CUR);
      fwrite(&p, sizeof(player), 1, f);
      return 1;
    }
  }
  return 0;
}

void readPlayer(char name[20], char surname[20], int *rank){
  printf("Enter player name: ");
  scanf("%s", name);
  printf("Enter player last name: ");
  scanf("%s", surname);
  printf("Enter new rank: ");
  scanf("%d", rank);
}