#include <stdio.h>

typedef enum
{
  Bluetooth = 128,
  Wifi = 64,
  GPS = 32,
  Datos = 16,
  Frontal = 8,
  Trasera = 4,
  Linterna = 2,
  Vibrar = 1,
} movil;

const ON = 255;
const OFF = 0;

int main(){
  movil mov = OFF;

  mov |= Wifi; //Encendemos el wifi

  mov ^= Wifi; //Marcamos un modulo como inactivo

  mov = ~mov; //Invertimos el estado actual

  mov &= Wifi; //Verificamos si el modulo esta activo

  return 0;
}