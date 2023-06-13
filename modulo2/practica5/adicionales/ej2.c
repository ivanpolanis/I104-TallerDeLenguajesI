#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "src/palabras.bin"
#define STR_SIZE 32
#define FILES 10

typedef struct
{
    char word[STR_SIZE];
    double frequency;
} Word;

void writeFiles();
Word *getArray(FILE *, int );

int main(){
    writeFiles();
    return 0;
}

void writeFiles(){
  FILE *f = fopen(PATH, "rb");
  fseek(f, 0, SEEK_END);
  int size = ftell(f) / sizeof(Word);
  fseek(f, 0, SEEK_SET);
  int capacity = 0;
  Word *arr = getArray(f, size);

  for (int i = 1; i <= FILES; i++){
    char path[STR_SIZE];
    sprintf(path, "data/palabras%d.bin", i);
    FILE *r = fopen(path, "wb");
    int k = (i<=size % FILES) ? 1 : 0; 
    for (int j = 0; j < size / FILES + k; j++){
      fwrite(&arr[capacity], sizeof(Word), 1, r);
      capacity++;
    }
    fclose(r);
  }
  fclose(f);
}

Word *getArray(FILE *f, int size){
  Word *arr = (Word *)malloc(sizeof(Word) * (size));
  int i = 0;
  while(fread(&arr[i], sizeof(Word), 1, f) != 0){
    i++;
  }
  for (int i = 0; i < size; i++){
    
  }
    return arr;
}