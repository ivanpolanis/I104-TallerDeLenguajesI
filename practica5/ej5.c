#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct
{
  char *word;
} DictionaryEntry;

void readDictionary(DictionaryEntry **, int *);
int isInDictionary(const DictionaryEntry *, int, char *);

int main()
{
  DictionaryEntry *dictionary;
  int size;

  readDictionary(&dictionary, &size);

  char word[BUFFER_SIZE];

  while (1)
  {
    printf("Enter a word: ");
    scanf("%s", word);

    if (strcmp(word, "ZZZ") == 0)
    {
      break;
    }

    if (isInDictionary(dictionary, size, word))
    {
      printf("The word \"%s\" is in the dictionary.\n", word);
    }
    else
    {
      printf("The word \"%s\" is not in the dictionary.\n", word);
    }
  }

  return 0;
}

void readDictionary(DictionaryEntry **dictionary, int *size)
{
  FILE *f = fopen("recursos/dictionary.txt", "r");

  if (f == NULL)
  {
    printf("An error has ocurred.");
    return;
  }

  char line[BUFFER_SIZE];
  *size = 0;
  int capacity = 10;

  *dictionary = malloc(capacity * sizeof(DictionaryEntry));

  while (fgets(line, BUFFER_SIZE, f) != NULL)
  {
    if (*size >= capacity)
    {
      capacity *= 2;
      *dictionary = realloc(*dictionary, capacity * sizeof(DictionaryEntry));
    }

    line[strcspn(line, "\n")] = '\0';
    (*dictionary)[*size].word = strdup(line);
    (*size)++;
  }

  fclose(f);
}

int isInDictionary(const DictionaryEntry *dictionary, int size, char *word)
{
  int left = 0, right = size;

  while (left <= right)
  {
    int mid = (left + right) / 2;
    int comparison = strcmp(word, dictionary[mid].word);
    if (comparison == 0)
    {
      return 1;
    }
    else if (comparison < 0)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return 0;
}