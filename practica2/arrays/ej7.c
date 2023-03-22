#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define YEARS 10
#define MONTHS 12
#define DAYS 30

void fillArr(int arr[YEARS][MONTHS][DAYS]){
  srand(time(NULL));
  for (int i = 0; i < YEARS; i++)
    for (int j = 0; j < MONTHS; j++)
      for (int k = 0; k < DAYS; k++)
        arr[i][j][k] = rand() % 300;
}
float getYearPromMax(float yearP[YEARS]){
  float max = 0;
  for (int i = 0; i < YEARS; i++)
    if (yearP[i] > max)
      max = yearP[i];
  return max;
}

void getMonthMin(int monthlyP[YEARS][MONTHS], int yearMin[YEARS]){
  for (int i = 0; i < YEARS; i++){
    int min = INT_MAX;
    for (int j = 0; j < MONTHS; j++)
      if (monthlyP[i][j] < min)
        min = monthlyP[i][j];
    yearMin[i] = min;
  }
}

int main(){
  int decade[YEARS][MONTHS][DAYS];
  fillArr(decade);
  int monthlyP[YEARS][MONTHS]={0};
  int yearMin[YEARS] = {0};
  float yearP[YEARS] = {0};
  for (int i = 0; i < YEARS;i++){
    for (int j = 0; j < MONTHS;j++){
      for (int k = 0; k < DAYS; k++){
        monthlyP[i][j] += decade[i][j][k];
      }
      yearP[i] += monthlyP[i][j];
    }
    yearP[i] /= MONTHS*DAYS;
    }


  getMonthMin(monthlyP, yearMin);
  float yearPromMax = getYearPromMax(yearP);
  printf("The year with the highest average is %.2f\n", yearPromMax);

  for (int i = 0; i < YEARS; i++)
    printf("Year %d: Month: %d\n", i+1, yearMin[i]);

  return 0;
}
