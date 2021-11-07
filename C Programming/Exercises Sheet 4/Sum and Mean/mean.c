#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *args[])
{
  double sum = 0;
  int n = atoi(args[1]);
  for (int i = 0; i <= n; i++)
  {
    sum += i;
  }

  printf("Sum: %f | Mean: %f\n", sum, sum/(n+1));
  return 0;
}
