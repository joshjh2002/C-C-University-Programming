#include <stdio.h>
#include <string.h>

void encode(char *string)
{
    //delcare all variables used
    int i; //used in for loop
    int counter = -1; //used to keep track of the number of consecutive latters
    char currentChar; //stores the current character the for loop has selected
    char previousChar = string[0]; //stores the character that the previous loop had selected

    for (i = 0; i <= strlen(string) - 1; i++)
    {
        currentChar = string[i];

        if (currentChar == previousChar)
        {
            counter++;
        }
        else
        {
            printf("%c%d", previousChar, counter); //prints the last character selected
            counter = 0;
        }
        
        previousChar = currentChar;
    }
    //prints the last character and letter
    printf("%c%d", previousChar, counter);
    printf("\n");
}

void decode(char *string)
{
    int i = 0;
    
    char characterToPrint = string[0];
    for (i = 1; i < strlen(string); i++)
    {
        
    }
}

int main(int argc, char *args[])
{

    int option = 0;
    if (strcmp(args[1], "D") == 0) // if args[1] == "D" then select option 1
        option = 1;
    else if (strcmp(args[1], "E") == 0) //if args[1] == "E", then select option 2
        option = 2;

    switch (option)
    {
    case 1:
    {
        break;
    }
    case 2:
    {
        encode(args[2]);
        break;
    }
    default: //when invalid option is selected
    {
        printf("Invalid Option\n");
        return 0;
        break;
    }
    }

    return 0;
}