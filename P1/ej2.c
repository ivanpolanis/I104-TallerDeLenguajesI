#include  <stdio.h>
int main(){
  char c = 'a';
  int x = 64;
  printf("char c= %c\n", x);
  printf("int x = %d\n", c);
  return 0;
}

/*
a. Cuando asignamos un char a un int, lo que sucede es que se asigna el valor del caracter que este presenta en el código asciii.
Si se hace al revés, cuando se imprima, se imprimira el carácter con respectivo valor en la tabla.
b. La diferencia entre float y double, son la cantidad de bytes de precisión que estos tienen para representar un numero.
c. Se respeta el orden de operaciones matematicas.
d. El operador sizeof sirve para saber cuantos bytes ocupa una variable en memoria.
*/