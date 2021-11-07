#include <stdio.h>
#include <stdlib.h>
#include "converter.h"
#include <string.h>
#include <math.h>

int convert(char *number1String)
{
  //printf("%s\n", number1String);
  int number = 0;
  int negative = 1;
  int numLen = strlen(number1String);

  // if there is a - at the beginning of the stream, it will make it negative
  if (number1String[0]== '-')
    negative = -1;

  for (int i = 0; i <= numLen; i++)
  {
    switch (number1String[i]) {
      case '1':
      {
        number += 1 * (pow(10, numLen - i - 1));
        break;
      }
      case '2':
      {
        number += 2 * (pow(10, numLen - i - 1));
        break;
      }
      case '3':
      {
        number += 3 * (pow(10, numLen - i - 1));
        break;
      }
      case '4':
      {
        number += 4 * (pow(10, numLen - i - 1));
        break;
      }
      case '5':
      {
        number += 5 * (pow(10, numLen - i - 1));
        break;
      }
      case '6':
      {
        number += 6 * (pow(10, numLen - i - 1));
        break;
      }
      case '7':
      {
        number += 7 * (pow(10, numLen - i - 1));
        break;
      }
      case '8':
      {
        number += 8 * (pow(10, numLen - i - 1));
        break;
      }
      case '9':
      {
        number += 9 * (pow(10, numLen - i - 1));
        break;
      }
      default:
      {
        break;
      }
    }
    //printf("%d ^ %d = %f | %c | %d\n",10, numLen - i - 1, pow(10, numLen - i - 1), number1String[i], number);
  }
  return number * negative;
}
