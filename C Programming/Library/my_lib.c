#include <my_lib.h>

int gcd(int x, int y)
{
  if (y == 0)
    return x;
    else
    return gcd(y, x%y);
  return x + y;
}

/*
1 function gcd(a,b)
2 if b = 0
3 return a;
4 else
5 return gcd(b, a mod b);
*/
