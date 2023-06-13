#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void imprimirNota(int n){
  switch (n)
  {
  case 4:
    printf("Tu nota es una A");
    break;
  case 3:
    printf("Tu nota es una B");
    break;
  case 2:
    printf("Tu nota es una C");
    break;
  case 1:
    printf("Tu nota es una D");
    break;
  case 0:
    printf("Tu nota es una F");
    break;
  default:
    break;
  }
}

int main(){
  int puntaje=0,a,b,aux;
  srand(time(NULL));
  for (int i = 0; i < 4;i++){
    a = rand() % 101;
    b = rand() % 101;
    printf("%d + %d = ", a, b);
    scanf("%d", &aux);
    if(aux == a+b){
      puntaje++;
    }
  }
  imprimirNota(puntaje);
  return 0;
}