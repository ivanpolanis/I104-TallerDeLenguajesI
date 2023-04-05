#include <stdlib.h>

//Enum correcto, se iniciliaza en (0,1,2)
typedef enum {
  IZQUIERDA,
  CENTRO_H,
  DERECHA
} AlineacionHorizontal;

//Enum correcto, se iniciliaza en (1,2,3)
typedef enum {
  ARRIBA = 1,
  CENTRO_V,
  ABAJO
} AlineacionVertical;

//Este enum no es correcto
typedef enum {
  DOS = 2,
  CERO = 0,
  UNO,
  MENOS_UNO = -1,
  OTRO
} Numeros;

//Este enum no es correcto
typedef enum {
  LET_A = "A",
  LET_B,
  LET_Z = "Z"
} Letras;

//Este enum es correcto ('a',b','z')
typedef enum {
  LETRA_A = 'A',
  LETRA_B,
  LETRA_Z = 'Z'
} Letras2;
