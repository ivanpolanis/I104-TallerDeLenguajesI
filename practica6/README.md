# **Práctica 6**

## **Argumentos al _main_ – Preprocesador – Bibliotecas**

### **Argumentos al _main_**

> _Nota: en el tutorial de Code::Blocks se explica cómo pasar argumentos a la función main en dicho entorno._

**1\.** Analice, compile y ejecute el siguiente código:

```c
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char* argv[]) {
  printf("\nargc = %d",argc);
  printf("\nargv[0] => %s",argv[0]);
  return 0;
}
```

¿Qué imprime? ¿Por qué?

**2\.** Escriba un programa que calcule e imprima el promedio de 4 números que se pasan como argumentos a la función _main_. En caso de no pasar la cantidad necesaria de parámetros, informar al usuario.

**3\.** _a._ Investigue las funciones de conversión de texto a número y escriba un programa “calculadora.c” que reciba dos números enteros y un operador como argumentos a la función main e imprima en pantalla el resultado de la operación. El operador debe ser: “+”, “-”, “/”, “.”. Si el operador recibido no es uno de los mencionados anteriormente, entonces el programa debe imprimir un mensaje de error.

_b._ Utilice una terminal para compilar el programa a través de la línea de comandos.

### **Preprocesador**

**4\.** Analice y ejecute el siguiente código:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SQUAREOF(x) x*x

int main() {
  int xin=3;
  printf("\nxin=%i",xin);
  printf("\nSQUAREOF(xin)=%i", SQUAREOF(xin));
  printf("\nSQUAREOF(xin+4)=%i", SQUAREOF(xin+4));
  printf("\nSQUAREOF(xin+xin)=%i", SQUAREOF(xin+xin));
}
```

_a._ ¿Qué es lo que hace?

_b._ La macro SQUAREOF debería calcular el cuadrado de un número. ¿Los resultados son los esperados?

¿Cuál es el problema?

_c._ Modifique la macro para que el cálculo sea correcto.

**5\.** Analice y ejecute el siguiente código:

```c
#include <stdio.h>

#include <stdlib.h>

#define size 25

void imprimir(int * v, int size){
  int i;
  for (i=0; i<size; i++){
    printf("v[%d]= %d", i, v[i]);
  }
}

int main(){
  int v[size];
  imprimir(v, size);
  return 0;
}
```

_a)_ ¿El código compila? Lea detenidamente el primer error que se detecta. ¿Cómo se explica?

_b)_ Identifique las etapas de _precompilación_ y _compilación_. ¿Qué es lo que está ocurriendo en cada

una?

_c)_ ¿Cómo podría solucionarse este problema?

**6\.** Realice un programa que defina una macro AREACIRCULO(r) que permita calcular el área de un círculo para un radio \_r. El cuerpo del programa debe generar aleatoriamente 10 valores diferentes que representan radios e imprimir el área correspondiente.

**7\.** El siguiente código debe imprimir el máximo entre las variables a y b. Complete la definición de la macro para lograr el objetivo.

```c
#include <stdio.h>

#include <stdlib.h>

#define MAX(x,y) ?

int main () {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("\n MAX(%d, %d) = %d", a, b, MAX(a,b));
  return 0;
}
```

**8\.** Analice y ejecute el siguiente código:

```c
#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0

int main(){
  int x= 15;
  while (x<50){
    #if DEBUG
    printf("x= %d", x);
    y= y+1;
    #endif
    x++;
  }
  return 0;
}
```

_a)_ ¿El código compila? ¿Por qué?

_b)_ ¿Qué sucedería al cambiar la constante simbólica DEBUG al valor 1? Evalúe el comportamiento del código. ¿Qué beneficios trae en este caso la compilación condicional?

_c)_ ¿Es posible cambiar el valor de la constante simbólica DEBUG en tiempo de ejecución?

_d)_ ¿Qué sucede si en lugar de utilizar la directiva #if se emplea #ifdef? ¿Incide el valor de la constante simbólica DEBUG en el resultado de la compilación?

**9\.** Realice un programa que genere un vector de 1000 enteros al azar y utilice una función para localizar un elemento. Se pide:

_a)_ Implementar la función de búsqueda que, dado un entero, retorne la posición donde se encuentra.

En caso de no existir el número retorne -1.

_b)_ Modificar a) para agregar información de depuración que permita imprimir en consola la cantidad de veces que se debió acceder al arreglo para encontrar (o no) el elemento en cada llamado a la función. Utilice las directivas del procesador para activar/desactivar la depuración e imprimir/no imprimir la información en la consola.

_c)_ Verifique el tamaño del programa compilando con la depuración y sin la depuración. Explique porque difieren.

### **Bibliotecas**

**10\.** Implemente la biblioteca imath.h, la cual contiene funciones matemáticas para enteros. La misma debe contener las siguientes funciones:

_a._ int potencia(int x, int y) – Eleva x a la y-ésima potencia.

_b._ int cuadrado(int x) – Eleva x al cuadrado.

_c._ int cubo(int x) – Eleva x al cubo.

_d._ int absoluto(int i) – Retorna el valor absoluto entero de i.

_e._ int factorial (int i) – Retorna el factorial de i.

_f._ int sumatoria (int i) – Retorna la sumatoria de 0 hasta i.

_g._ int multiplo (int x, int y) – Retorna 1 si y es divisor de x, 0 en otro caso.

_h._ int divisor (int x, int y) – Retorna 1 si y es múltiplo de x, 0 en otro caso.

_i._ int par (int i) – Retorna 1 si i es par, 0 en otro caso.

_j._ int impar (int i) – Retorna 1 si i es impar, 0 en otro caso.

Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros e imprima el cuadrado y el cubo de aquellos números que son pares y el factorial de aquellos que son impares. La lectura finaliza con el ingreso del 0.

**11\.** _a._ Implemente la biblioteca istack.h, la cual debe contener tipos y operaciones necesarias para manipular una estructura de datos pila que almacene números enteros. Una pila es una estructura de datos homogénea y dinámica. El acceso a la misma se dice que es de tipo LIFO (Last In First Out), lo que quiere decir que los elementos se recuperan en el orden inverso en que fueron insertados. Implemente al menos las siguientes funciones:

_a._ Stack\* s_create () – Retorna una nueva pila. Se debe invocar antes de manipular cualquiera de ellas.

_b._ int s_push(stack\* s, int n) – Apila n en s. Retorna el elemento apilado.

_c._ int s_pop (stack\* s) – Desapila un elemento de s.

_d._ int s_top (stack s) – Retorna el próximo elemento que será desapilado.

_e._ int s_empty(stack s) – Retorna 1 si s está vacía, 0 en caso contrario.

_f._ int s_length(stack s) – Retorna la cantidad de elementos apilados en s.

b. Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros y los inserte en una pila. A continuación, desapile los elementos para verificar si funciona correctamente. La lectura finaliza con el ingreso del 0.

c. Manteniendo la misma interfaz, modifique el tipo de datos **_stack_** y reimplemente la biblioteca para que la función **_s_length_** retorne la cantidad de elementos sin recorrer la pila.

**12\.** Implemente una biblioteca diccionario.h que permita manejar un diccionario de palabras. Determine las estructuras de datos necesarias para implementar la biblioteca. Las operaciones que debe implementar son las siguientes:

_a)_ Crear un diccionario: inicializa la estructura del diccionario.

_b)_ Agregar palabra: agrega una nueva palabra al diccionario siempre y cuando no exista. Retorna si la agregó o no.

_c)_ Existe palabra: determina si una palabra está en el diccionario o no.

_d)_ Eliminar palabra: elimina una palabra del diccionario. Retorna si la palabra fue eliminada o no.

_e)_ Cargar desde un archivo: carga un diccionario desde un archivo de texto.

_f)_ Guardar a un archivo: guarda un diccionario en un archivo de texto.

_g)_ Destruir el diccionario: libera los recursos del diccionario.

Una vez implementadas todas las funciones de biblioteca, escriba un programa que permita probarlas.
