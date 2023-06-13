#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "istack.h"


int main(){
  Stack stack = create();
  int i;
  srand(time(NULL));
  for (i=0; i<10; i++){
    s_push(&stack, rand()%1000);
  }
  while (!s_empty(&stack))
  {
    printf("%d\n", s_pop(&stack));
  }
  return 0;
} 