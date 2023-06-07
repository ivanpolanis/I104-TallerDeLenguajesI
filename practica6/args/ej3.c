#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getOperator(char *op);

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("You must enter 3 arguments.", argv[0]);
    return 1;
  }
  int op = getOperator(argv[2]);
  if (op == 0)
  {
    printf("The operator is not valid.");
    return 1;
  }
  int result = 0;
  switch (op)
  {
  case 1:
    result = atoi(argv[1]) + atoi(argv[3]);
    break;
  case 2:
    result = atoi(argv[1]) - atoi(argv[3]);
    break;
  case 3:
    result = atoi(argv[1]) * atoi(argv[3]);
    break;
  case 4:
    result = atoi(argv[1]) / atoi(argv[3]);
    break;
  }
  printf("%s %s %s: %d", argv[1], argv[2], argv[3], result);
}

int getOperator(char *op)
{
  if (strcmp(op, "+") == 0)
  {
    return 1;
  }
  else if (strcmp(op, "-") == 0)
  {
    return 2;
  }
  else if (strcmp(op, "*") == 0)
  {
    return 3;
  }
  else if (strcmp(op, "/") == 0)
  {
    return 4;
  }
  else
  {
    return 0;
  }
}