#include <stdio.h>

int incremento(int n){
  static int j = 0;
  j++;
  return (n % 2 ? n : n + j);
}

int main(){
  float i;
  for (i = 6; i > 0.5;i/=2){
    printf("i=%5.1f j=%5d\n", i, incremento(i));
  }
  return 0;
}