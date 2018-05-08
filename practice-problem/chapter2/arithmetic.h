#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <stdio.h>
#include <math.h>

int uadd_ok(unsigned x, unsigned y);

int uadd_ok(unsigned x, unsigned y)
{
  unsigned u_mask = 0;
  //printf("%ld\n", sizeof(unsigned));
  u_mask = pow(2, (sizeof(unsigned) * 8) - 1) - 1;
  x = u_mask - x;
  if (y>x)
    return 1;
  return 0;
}

#endif
