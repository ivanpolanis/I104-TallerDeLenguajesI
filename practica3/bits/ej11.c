#include <stdio.h>

typedef struct
{
  unsigned seg : 5;
  unsigned min : 6;
  unsigned hora : 5;
} horario;

int main()
{
  horario h;
  int value;

  printf("Ingrese una hora: ");
  scanf("%d", &value);
  if( value > 23){
    value -= 24;
  }
  h.hora = value;


  printf("Ingrese min: ");
  scanf("%d", &value);
  if(value > 59){
    value -= 60;
  }
  h.min = value;

  printf("Ingrese seg: ");
  scanf("%d", &value);

  if (value > 31)
  {
    if (h.min == 59)
    {
      h.min = 0;
      if (h.hora == 23)
        h.hora = 0;
      else
        h.hora++;
    }
    else
    {
      h.min++;
    }
  }
  else
    h.seg = value;

  printf("La hora ingresada fue %02d:%02d:%02d", h.hora, h.min, h.seg);
  return 0;
}