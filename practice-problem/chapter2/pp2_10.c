#include <stdio.h>

void inplace_swap(int *x, int *y);

int main()
{
  return 0;
}

void inplace_swap(int *x, int *y)
{
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}
