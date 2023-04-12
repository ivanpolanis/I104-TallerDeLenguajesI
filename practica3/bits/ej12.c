#include <stdio.h>

typedef struct
{
  unsigned red : 8;
  unsigned green : 8;
  unsigned blue : 8;
} RGB24;

typedef struct
{
  unsigned red : 5;
  unsigned green : 6;
  unsigned blue : 5;
} RGB16;

RGB24 RGB16to24(RGB16);
RGB16 RGB24to16(RGB24);

int main()
{
  RGB16 rgb16;
  RGB24 rgb24;

  rgb24.red = 123;
  rgb24.green = 71;
  rgb24.blue = 255;

  rgb16 = RGB24to16(rgb24);

  printf("RGB16: %d %d %d\n", rgb16.red, rgb16.green, rgb16.blue);

  printf("RGB24: %d %d %d\n", rgb24.red, rgb24.green, rgb24.blue);


  return 0;
}

RGB24 RGB16to24(RGB16 c)
{
  RGB24 rgb;
  rgb.red = c.red;
  rgb.green = c.green;
  rgb.blue = c.blue;
  return rgb;
}

RGB16 RGB24to16(RGB24 c)
{
  RGB16 rgb;
  if (c.red > 31)
    rgb.red = 31;
  else
    rgb.red = c.red;

  if (c.green > 63)
    rgb.green = 63;
  else
    rgb.green = c.green;

  if (c.blue > 31)
    rgb.blue = 31;
  else
    rgb.blue = c.blue;

  return rgb;
}