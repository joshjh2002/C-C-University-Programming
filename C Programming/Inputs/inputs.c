#include <stdio.h>

int main()
{
  printf("Enter Name: ");
  char str[20] = "";
  fgets(str, 20,stdin); //gets a user input and drops it down a line
  printf("Your name is: %s", str);
  return 0;
}
