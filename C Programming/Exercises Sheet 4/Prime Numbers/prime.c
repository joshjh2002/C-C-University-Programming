#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int number); //the function is defined

int main(int argv, char *args[])
{
  int number = atoi(args[1]);

  isPrime(number) == 1 ? printf("%d is a prime number\n", number) : printf("%d is not a prime number\n", number);
}

//this is the code for the isPrime() function
int isPrime(int number)
{
  int absNum = abs(number);

  for (int i = 2; i < absNum; i++)
  {
    if (absNum % i == 0)
    {
      return 0;
    }
  }

  return 1;
}
