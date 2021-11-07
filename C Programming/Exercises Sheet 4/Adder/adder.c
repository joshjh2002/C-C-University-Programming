#include <stdio.h>
#include <stdlib.h>
#include "converter.h"

int main(int argv, char *args[])
{
  int num1 = convert(args[1]);
  int num2 = convert(args[2]);

  int answer = num1 + num2;

  printf("%d + %d = %d\n", num1, num2, answer);

  return 0;
}
