#include "lookup.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    init();
    int x; 
    int y;
    int i = 0;
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            void* ptr = (void*)malloc(sizeof(int));
            ptr = i;
            i++;
        }
    }
    
    printMatrix();
}