#include <stdio.h>

union dim
{
  struct
  {
    struct
    {
      unsigned x1, y1
    };
    struct
    {
      unsigned x2, y2;
    };
  } forma1;
  struct
  {
    struct
    {
      unsigned x, y;
    };
    struct
    {
      unsigned ancho, alto;
    };
  } forma2;
  struct
  {
    unsigned x, y, ancho, alto;
  } forma3;
};