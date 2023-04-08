# **Práctica 1**

## **Tipos de datos simples y estructuras de control**

## **Funciones – Identificadores**

> **Importante:** Para el desarrollo de ésta práctica y las siguientes, compile utilizando el _flag_ –Wall. En el tutorial de Code::Blocks se explica cómo activar éste _flag_ para ese entorno.

**1\.** Al compilar un programa en C, el compilador puede notificar errores y avisos (_warnings_). ¿Qué diferencia existe entre ellos? ¿puede un programa compilar con errores? ¿y con _warnings_? Compile los siguientes programas e identifique errores y _warnings_. Luego, corríjalos para que el código compile correctamente.

_a._

```c
#include <stdio.h>
int main()
{
  double pi = 3.14;
  int y = 5
  printf("pi = %d\n",pi);
}
```

_b._

```c
#include <stdio.h>
int main(){
  int x=10;
  if (x=5)
    printf("x = 5\n");
return 0;
}
```

**2\.** Investigue los diferentes tipos de datos del lenguaje C y luego responda:

_a._ ¿Qué ocurre cuando asignamos un char a un int? ¿y al revés? Ejecute el siguiente código y analice lo que imprime. ¿Se presenta algún _warning_ al compilar?

```c
#include <stdio.h>

int main(){
  char c= 'a';
  int x= 64;
  printf("char c= %c\n", x);
  printf("int x= %d\n", c);
  return 0;
}
```

_b._ ¿Qué diferencia existe entre los tipos float y double? ¿se puede asignar entre si sin inconvenientes?

_c._ ¿Qué sucede cuando en una operación intervienen operadores diferentes?

Por ejemplo:

$$
x = 2*32+10 \% 2 - 1;
$$

_d._ Investigue el operador sizeof*.* ¿Para qué sirve? Luego aplíquelo y verifique el tamaño de los distintos tipos de datos en su máquina.

**3\.** Números naturales y enteros en C:

_a._ ¿Qué tipos de datos pueden usarse para representar enteros en C?

_b._ ¿Qué modificadores pueden utilizarse con estos tipos?

_c._ Para cada combinación de tipo y modificadores indique el tamaño en bytes que ocupa, el sistema de representación binario y el rango del mismo.

**4\.** Investigue los operadores del lenguaje C. Enumérelos y descríbalos según las siguientes categorías: aritméticos, relacionales, lógicos, de bits, asignación y condicional.

**5\.** Escriba un programa que imprima en pantalla todos los números enteros múltiplos de 5 comprendidos entre 1 y 50. Realice dos soluciones con las siguientes características:

_a._ Utilizando el operador _%_ para determinar cuándo un número es múltiplo de 5.

_b._ Utilizando un _for_ donde la variable índice se incremente en 5 unidades por cada iteración.

**6\.** Escriba un programa que, a partir de un número flotante leído desde teclado, el cual representa una distancia en kilómetros, imprima su equivalente en millas.

> Nota: 1,61 Km ≈ 1 milla.

**7\.** El objetivo del siguiente código es leer dos caracteres de teclado e imprimirlos en pantalla. ¿El código cumple con su cometido? En caso negativo, corríjalo para que lo haga.

```c
#include <stdio.h>

int main(){
  char a, b;
  printf("Ingrese el primer caracter:\n");
  scanf("%c", &a);
  printf("Se leyó el caracter: %c\n", a);
  printf("Ingrese el segundo caracter:\n");
  scanf("%c", &b);
  printf("Se leyó el caracter: %c\n", b);
  return 0;
}
```

**8\.** Identifique y corrija los errores en cada uno de los siguientes códigos:

> Nota: puede haber más de uno

_a._

```c
  int edad;
  if (edad >= 40);
    printf("Tiene %d años o más",&40);
  else
    printf("Tiene menos de %d años",&40);
```

_b._

```c
  int total, x = 1;
  while (x <= 10) {
    total += x;
    ++x;
  }
  printf("Total = %f",total);
```

_c._

```c
  int valor;
  scanf("%d",&valor);
  switch (valor % 2){
    case 0: printf("El valor es par");
    case 2: printf("El valor es impar");
  }
```

_d._

```c
  int x, y;
  scanf("%d",x);
  scanf("%d",y);
  printf( x + y = %d ,x+y);
```

**9\.** Escriba un programa que lea 2 números enteros y un carácter, el cual debe corresponderse con un operador matemático (+, -, /, x), y a partir de ellos imprima el resultado de realizar la operación pedida en pantalla. En caso de que el carácter no represente un operador válido, imprima un mensaje de error. Reflexione sobre las diferentes estructuras de control que puede utilizar.

**10\.** Indique detalladamente la estructura de control **for** de C. Indique cual es la finalidad de cada parte, si es opcional u obligatoria y en que parte del bloque for se ejecuta/evalua cada una.

**11\.** Indique qué valores de la variable de control _i_ se imprimen para cada una de las siguientes estructuras de control _for_. Ejecute cada código y analice por qué ocurre cada caso:

_a._

```c
  for (i = 0; i <= 11; i++)
    printf("%d\n",i);
```

_b._

```c
  for (i = 0; i <= 11; ++i)
    printf("%d\n",i);
```

_c._

```c
  for (i = 2; i <= 11; i+=2)
    printf("%d\n",i);
```

_d._

```c
  for (i = 1; i <= 11; i*=2)
    printf("%d\n",i);
```

_e._

```c
  for (i = 11; i >= 1; i-=2)
    printf("%d\n",i);
```

_f._

```c
  for (i = 11; i > 1; i=+1)
    printf("%d\n",i);
```

**12\.** Escriba un programa que imprima la raíz cuadrada, el cuadrado y el cubo de los números enteros comprendidos en el rango 1..10.

> Nota: para calcular la raíz cuadrada y la potencia de un número investigue las funciones sqrt() y pow(), ambas de la librería <math.h>.

**13\.** Un número primo es un número natural mayor que 1, que tiene dos divisores distintos únicamente: él mismo y el 1.

_a._ Escriba una función que reciba como parámetro un número entero _n_ y determine si el mismo es primo o no.

_b._ Escriba un programa que lea números enteros desde teclado hasta que la cantidad de números primos leídos sea 5.

**14\.** Escriba una función que reciba un número entero y retorne el número resultante de invertir la posición de todos sus dígitos. Por ejemplo, si se pasa como argumento el número 1234 la función deberá retorna el número 4321.

**15\.** Para todo número natural _n_, se llama _factorial de n_ al producto de todos los naturales desde 1 hasta _n_:

$$
n! = 1\times2\times3\times\cdots\times(n-1)\times n
$$

Escriba una función que reciba como parámetro un número entero y retorne como resultado el número factorial del mismo.

_a._ Resolviéndolo de forma iterativa.

_b._ Resolviéndolo de forma recursiva.

**16\.** Analice y ejecute el siguiente código:

```c
void swap(int a, int b);

int main()
{
  int x, y;
  x = 10;
  y = 20;
  printf("x=%d\ty=%d\n",x,y);
  swap(x, y);
  printf("x=%d\ty=%d\n",x,y);
  return 0;
}
```

```c
void swap(int a,int b)
{
  int tmp;

  tmp = a;
  a = b;
  b = tmp;
}
```

Se supone que la función swap intercambia el valor de sus dos parámetros enteros, ¿funciona correctamente? Si no es así, modifique la función swap para que lo haga.

**17\.** Escriba una función que reciba como argumento un número entero ny que dentro de ella lea n números flotantes desde teclado. La función debe retornar el mínimo y el máximo número leído.

**18\.** Escriba un programa que imprima 15 números generados pseudo-aleatoriamente. ¿La secuencia generada es siempre la misma? ¿Por qué? ¿Qué se puede hacer para generar secuencias pseudo- aleatorias diferentes?

> Nota: para generar números en forma pseudo-aleatoria investigue las funciones rand() y srand()_,_ las cuales se encuentran definidas en la biblioteca <stdlib.h>.

**19\.** Una escuela primaria desea evaluar si sus alumnos son capaces de resolver operaciones matemáticas de suma de números enteros. Para ello se pide realizar un programa que muestre al alumno 4 operaciones de suma y le pida que ingrese sus correspondientes resultados. Los operandos de las operaciones a resolver deben ser generados aleatoriamente y deben estar en el rango de 0 a 100. Cada operación respondida de forma correcta suma 1 punto. Al finalizar informar la nota obtenida por el alumno de acuerdo a la siguiente tabla:

| Puntaje |  4  |  3  |  2  |  1  |  0  |
| :-----: | :-: | :-: | :-: | :-: | :-: |
|  Nota   |  A  |  B  |  C  |  D  |  E  |

> Nota: para asegurar que un número se encuentre en el rango de 0 a N, puede utilizar el operador % con (N+1) como segundo operando.

**20\.** Desarrolle una función llamada damePar(), la cual debe retornar un número entero. damePar() devuelve 0 en el primer llamado, 2 en el segundo, 4 en el tercero, y así sucesivamente. Luego, escriba un programa que lea un número entero positivo n desde teclado y utilizando damePar() imprima los primeros n números pares. No utilice variables globales.

**21\.** Analice el siguiente programa e indique qué imprime:

```c
#include <stdio.h>

int incremento(int);

int main(){
  float i;
  for(i=6; i>0.5; i/=2)
  printf("i=%5.1f j=%5d\n", i, incremento(i));
  return 0;
}

int incremento(int N)
{
  static int j=0;
  j++;
  return (N%2 ? N : N+j);
}
```
