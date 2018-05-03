#ifndef BITFUN_H
#define BITFUN_H

#include <stdio.h>

void inplace_swap(int *x, int *y);

void inplace_swap(int *x, int *y)
{
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

#endif
