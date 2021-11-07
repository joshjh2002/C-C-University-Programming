#include <stdlib.h>
#include <stdio.h>
#include "stats.h"
#include <string.h>

int main(int argc, char *args[])
{
    int i;
    double numbers[(argc-1)];

    for (i = 2; i < argc; i++)
    {
        printf(args[i]);
        printf("\n%d\n", atoi(args[i]));
        numbers[i-2] = atoi(args[i]);
    }
    printf("%d\n", numbers[0]);
    int operation = 0;



    if (strcmp(args[1], "mean"))
    {
        operation = 1;
    }
    else if (strcmp(args[1], "max"))
    {
        operation = 2;
    }
    else if (strcmp(args[1], "sd"))
    {
        operation = 3;
    }

    switch (operation)
    {
        case 1:
        {
            printf("%d\n", my_mean(numbers, argc - 2));
            break;
        }
        case 2:
        {
            printf("%d\n", my_max(numbers, argc - 2));
            break;
        }
        case 3:
        {
            printf("%d\n", my_sd(numbers, argc - 2));
            break;
        }
        default:
        {
            printf("Invalid Operation");
            break;
        }
    }
    return 0;
}