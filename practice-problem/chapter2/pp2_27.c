#include "arithmetic.h"

int main(int argc, char **argv)
{
  unsigned x = 0;
  unsigned y = 0;

  scanf("%d %d",&x, &y);
  if(uadd_ok(x, y))
    return 1;
  return 0;
}
