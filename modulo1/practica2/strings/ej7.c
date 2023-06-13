#include <stdio.h>
#include <string.h>

int isPalindrome(char string[]){
  int left = 0;
  int right = strlen(string) - 1;
  while(left < right){
    if(string[left]!=string[right])
      return 0;
    left++;
    right--;
  }
  return 1;
}

int esPalindromo(char *string)
{
  char *aux1 = string;
  char *aux2 = string + strlen(string) - 1;
  while(aux1<aux2){
    if(*aux1!=*aux2)
      return 0;
    aux1++;
    aux2--;
  }
  return 1;
}

int main(){
  char string[255];
  printf("Ingrese una palabra: ");
  scanf("%s", string);
  printf("%d\n", esPalindromo(string));
  printf("%d", isPalindrome(string));
  return 0;
}