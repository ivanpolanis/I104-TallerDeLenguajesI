# **Práctica 5 - Adicional**

## **Archivos de texto y archivos binarios**

**1)** Dado un archivo de texto que contiene una palabra por cada línea, implemente un programa que lo convierta a su correspondiente versión binaria agregando un valor de dificultad asociado a la frecuencia de sus letras\. Dicho valor de dificultad de una palabra esta dado por la suma de los cuadrados de la frecuencia (ver tabla) de cada una de las letras que la compone\. Solo agregue aquellas palabras que tengan entre 4 y 14 letras\.

|   A   |  B   |  C   |  D   |   E   |  F   |  G   |  H   |  I   |  J   |  K   |  L   |  M   |
| :---: | :--: | :--: | :--: | :---: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 12,53 | 1,42 | 4,68 | 5,86 | 13,68 | 0,69 | 1,01 | 0,70 | 6,25 | 0,44 | 0,01 | 4,97 | 3,15 |

|  N   |  Ñ   |  O   |  P   |  Q   |  R   |  S   |  T   |  U   |  V   |  W   |  X   |  Y   |  Z   |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 6,71 | 0,31 | 8,68 | 2,51 | 0,88 | 6,87 | 7,98 | 4,63 | 3,93 | 0,90 | 0,02 | 0,22 | 0,90 | 0,52 |

$$
d(p)=\sum_{i=1}^{long(p)}f(p[i])^2
$$

**Notas:**

- _Tenga en cuenta que como va a trabajar en C con texto en formato ASCII extendido (y normalmente los
  editores texto utilizan ANSI o UTF) puede tener problemas con las letras acentuadas y con las eñes al
  editar archivos de prueba. Se recomienda no utilizar palabras con dichas características._
- _Asegúrese que en el archivo binario no quede del carácter “\n”._

**2)** Cargue completamente en memoria el archivo generado en el punto anterior y ordénelo por dificultad\. Luego divida las palabras en 10 partes iguales, manteniendo el orden, y almacénelas en 10 archivos
diferentes\. Para realizar la ordenación puede utilizar una implementación propia o también puede utilizar alguna de un tercero como la siguiente: [https://beginnersbook\.com/2015/02/quicksort-in-c](https://beginnersbook.com/2015/02/quicksort-program-in-c/)

**3)** Implemente el juego del ahorcado\. Este es un juego de adivinanzas
donde la computadora selecciona una palabra con cierta dificultad para
que un jugador humano la adivine\.

Cuando se lanza la aplicación muestra un menú de opciones donde se
puede comenzar un juego con la opción **Jugar**, finalizar la aplicación
con la opción **Salir** o configurar el juego a través del menú **Dificultad**.

_Menú Jugar:_

El juego inicia con la selección de una palabra al azar por parte de la
computadora de acuerdo con el criterio establecido en el nivel de
dificultad.

Una vez elegida la palabra se muestra la horca y el espacio reservado
para cada una de las letras de la palabra.

Luego el jugador ingresa una a una las letras hasta que finalice el
juego. Si la letra coincide con una o más letras de la palabra, estas se
muestran en el espacio correspondiente. En cambio, si la letra no
pertenece a la palabra, se agrega al gráfico de la horca una parte más del cuerpo. El juego termina
cuando el jugador gana completando todas las letras de la palabra o pierde fallando 7 letras sin
completar la palabra.

_Menú Dificultad:_

El nivel de dificultad del juego consiste en un número del 1 (difícil) al 10 (fácil) y está asociado con
uno de los 10 archivos generados en el ejercicio anterior: nivel 1➔ archivo 1, … , nivel 10 ➔ archivo

10\. Al momento de jugar se debe seleccionar una palabra al azar dentro de uno del archivo asociado
al nivel.
