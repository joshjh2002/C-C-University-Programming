#include <stdlib.h>
#include <stdio.h>
//#include "stats.h"
#include <string.h>

int main(int argc, char *args[])
{
    int i;
    double numbers[(argc-1)];

    for (i = 2; i < argc; i++)
    {
        //printf(args[i]);
        //printf("\n%d\n", atoi(args[i]));
        numbers[i-2] = atoi(args[i]);
    }
    printf("%d\n", numbers[0]);
}