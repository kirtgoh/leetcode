#include <math.h>
#include "solution.h"

int Solution::reverse(int x)
{
  int ri = 0;
  while (x)
  {
    int t = x % 10;
    ri *= 10;
    ri += t;
    x /= 10;
  }

  return ri;
}

