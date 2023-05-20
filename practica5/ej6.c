#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct
{
  float *min, *max, *avg;
} t_values;

void readFile(t_values *, int *);
int writeReport(t_values, int);

int main()
{
  t_values values;
  int fields = 0;
  readFile(&values, &fields);
  writeReport(values, fields);

  free(values.min);
  free(values.max);
  free(values.avg);
  return 0;
}

void writeField(FILE *f, float *arr, int fields, char *str)
{
  fprintf(f,"%s:", str);
  for (int i = 0; i < fields; i++)
  {
    fprintf(f, "%.2f|", arr[i]);
  }
  fprintf(f, "\n");
}

int writeReport(t_values values, int fields)
{
  FILE *report_file = fopen("recursos/reporte_vinos.txt", "w");
  if(report_file == NULL){
    printf("An error has ocurred.");
    return 1;
  }
  writeField(report_file, values.min, fields, "Min");
  writeField(report_file, values.max, fields, "Max");
  writeField(report_file, values.avg, fields, "Avg");
  fclose(report_file);
}

void readFile(t_values *values, int *fields)
{
  FILE *csv_file = fopen("recursos/vinos.csv", "r");

  if (csv_file == NULL)
  {
    printf("An error has ocurred.");
  }

  char line[MAX_LENGTH];

  if (fgets(line, MAX_LENGTH, csv_file) == NULL)
  {
    printf("The file is empty");
    fclose(csv_file);
    return;
  }

  *fields = 0;
  char *field = strtok(line, ";");
  while (field != NULL)
  {
    (*fields)++;
    field = strtok(NULL, ";");
  }

  float *min = (float *)malloc(*fields * sizeof(float));
  float *max = (float *)malloc(*fields * sizeof(float));
  float *avg = (float *)malloc(*fields * sizeof(float));

  for (int i = 0; i < *fields; i++)
  {
    min[i] = FLT_MAX;
    max[i] = -FLT_MAX;
    avg[i] = 0;
  }

  int lines = 0;
  while (fgets(line, MAX_LENGTH, csv_file) != NULL)
  {
    field = strtok(line, ";");
    int index = 0;

    while (field != NULL)
    {
      float value = atof(field);
      if (value > max[index])
      {
        max[index] = value;
      }
      else if (value < min[index])
      {
        min[index] = value;
      }

      avg[index] += value;
      field = strtok(NULL, ";");
      index++;
    }
    lines++;
  }
  printf("%d", lines);
  for (int i = 0; i < *fields; i++)
  {
    avg[i] /= lines;
  }

  values->min = min;
  values->max = max;
  values->avg = avg;
  fclose(csv_file);
}