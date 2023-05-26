#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 1024

typedef struct
{
  size_t position;
  long dni;
} t_idx;

typedef struct
{
  unsigned id, dni;
  char *surname, *name, *work, *mail, *city, *country;
} person;

void createIndexFile(FILE *csv, t_idx **index, size_t *size);
void insert(t_idx **arr, size_t *capacity, t_idx data);
void printIdx();
void heapify(t_idx arr[], int n, int i);
void heapSort(t_idx arr[], int n);
int buscar(FILE *csv, t_idx *index, size_t size, int dni, person *p);
void printPerson(person p);
size_t binarySearch(t_idx *index, int size, int dni);

int main()
{
  FILE *csv = fopen("recursos/personas.csv", "r");
  t_idx *idx;
  size_t size;
  createIndexFile(csv, &idx, &size);
  person p;
  if(buscar(csv, idx, size,57297307, &p)){
  printPerson(p);
  }
  return 0;
}

void createIndexFile(FILE *csv, t_idx **index, size_t *size)
{
  FILE *idx = fopen("recursos/personas.idx", "wb");
  char buffer[SIZE];
  char *field;

  size_t capacity = 1;
  t_idx *arr = (t_idx *)malloc(capacity * sizeof(t_idx));

  fgets(buffer, SIZE, csv);
  size_t bytes = ftell(csv);

  while (fgets(buffer, SIZE, csv) != NULL)
  {
    field = strtok(buffer, ";");
    field = strtok(NULL, ";");
    t_idx aux = {bytes, atoi(field)};
    insert(&arr, &capacity, aux);
    bytes = ftell(csv);
  }
  heapSort(arr, capacity);
  for (int i = 1; i < capacity; i++)
  {
    fwrite(&arr[i], sizeof(t_idx), 1, idx);
  }
  fclose(idx);
  *index = arr;
  *size = capacity;
}

void insert(t_idx **arr, size_t *capacity, t_idx data)
{
  (*capacity)++;
  t_idx *temp = (t_idx *)realloc(*arr, *capacity * sizeof(t_idx));
  if (temp == NULL)
  {
    printf("Error reallocating memory.");
    exit(EXIT_FAILURE);
  }
  *arr = temp;
  int n = *capacity - 1;
  while (n / 2 > 0 && (*arr)[n / 2].dni > data.dni)
  {
    (*arr)[n] = (*arr)[n / 2];
    n /= 2;
  }
  (*arr)[n] = data;
}

void printPerson(person p)
{
  printf("%d %d %s %s %s %s %s %s\n", p.id, p.dni, p.surname, p.name, p.work, p.mail, p.city, p.country);
  printf("naseh");
}

int buscar(FILE *csv, t_idx *index, size_t size, int dni, person *p)
{
  size_t pos = binarySearch(index, size, dni);
  char buffer[SIZE];
  char *field;
  if (pos)
  {
    fseek(csv, pos, SEEK_SET);
    if (fgets(buffer, SIZE, csv) != NULL)
    {
      char *field = strtok(buffer, ";");
      p->id = atoi(field);
      field = strtok(NULL, ";");
      p->dni = atoi(field);
      field = strtok(NULL, ";");
      p->surname = strdup(field);
      field = strtok(NULL, ";");
      p->name = strdup(field);
      field = strtok(NULL, ";");
      p->work = strdup(field);
      field = strtok(NULL, ";");
      p->mail = strdup(field);
      field = strtok(NULL, ";");
      p->city = strdup(field);
      field = strtok(NULL, ";");
      p->country = strdup(field);
      return 1;
    }
  }
  return 0;
}

size_t binarySearch(t_idx *index, int size, int dni)
{
  int left = 0, right = size;

  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (dni == index[mid].dni)
    {
      return index[mid].position;
    }
    else if (dni < index[mid].dni)
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

void printIdx()
{
  FILE *idx = fopen("recursos/personas.idx", "rb");
  t_idx aux;
  while (fread(&aux, sizeof(t_idx), 1, idx) != 0)
  {
    printf("%ld %ld\n", aux.dni, aux.position);
  }
  fclose(idx);
}

void heapify(t_idx arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left].dni > arr[largest].dni)
  {
    largest = left;
  }

  if (right < n && arr[right].dni > arr[largest].dni)
  {
    largest = right;
  }

  if (largest != i)
  {
    t_idx temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}

void heapSort(t_idx arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--)
  {
    t_idx temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}