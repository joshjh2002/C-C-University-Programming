#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argv, char *args[])
{
  int isPalindrome = 1;
  char *originalWord = args[1];
  char *word = originalWord;

  int length = strlen(originalWord) - 1;

  for (int i = 0; i < length; i++)
  {
    word[i] = (char)tolower((int)word[i]);
  }

  for (int i = 0; i < length / 2 - 1; i++)
  {
    if (word[i] != word[length-i])
    {
      isPalindrome = 0;
      break;
    }
  }

  isPalindrome == 1 ? printf("%s is a palindrome\n", originalWord) : printf("%s is not a palindrome\n", originalWord);;

  return 0;
}
