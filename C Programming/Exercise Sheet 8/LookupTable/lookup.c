#include "lookup.h"

void *matrix[10][10];

void init()
{
    int x = 0;
    int y = 0;
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            matrix[x][y] = NULL;
        }
    }
}

void set(int x, int y, void *value)
{
    matrix[x][y] = value;
}

void *get(int x, int y)
{
    return matrix[x][y];
}

void printMatrix()
{
    int x = 0;
    int y = 0;
    printf("\n");
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            int *temp = matrix[x][y];
            printf("%d", *temp);
            printf("    ");
        }
        printf("\n");
    }
}