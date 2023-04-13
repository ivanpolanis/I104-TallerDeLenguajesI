#include <stdio.h>

typedef struct {
  unsigned char Bluetooth : 1;
  unsigned char Wifi : 1;
  unsigned char GPS : 1;
  unsigned char Datos : 1;
  unsigned char Frontal : 1;
  unsigned char Trasera : 1;
  unsigned char Linterna : 1;
  unsigned char Vibrar : 1;
} movil;


int main(){
  movil mov = {0,0,0,0,0,0,0,0};

  mov.Wifi = 1; //Encendemos el wifi

  mov.Wifi = 0; //Marcamos un modulo como inactivo

  mov.Wifi = !mov.Wifi; //Invertimos el estado actual

  mov.Wifi = mov.Wifi & 1; //Verificamos si el modulo esta activo

  return 0;
}