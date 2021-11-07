#include <stdio.h>
#include "my_lib.h" // angled brackets for user libraries
#include <stdlib.h>

int main(int argv, char *args[])
{
  int x = atoi(args[1]);
  int y = atoi(args[2]);
  printf("%d\n", gcd(x,y));
  return 0;
}

//atio converts text to int
