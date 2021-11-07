#include <stdio.h>

int main()
{
  int num1 = 0;
  int num2 = 0;

  printf("Enter Number 1: ");
  scanf("%d", &num1);
  printf("Enter Number 2: ");
  scanf("%d", &num2);

  int sum = num1 + num2;

  printf("The sum of %d and %d is %d", num1, num2, sum);

  return 0;
}
