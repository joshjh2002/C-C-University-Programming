#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "datasetgeneration.h"

void main(int argv, char *args[])
{
    if (argv <= 3)
    {
        printf("Please input the required parameters: <max number size> <data set size> <search set size>");
        return;
    }

    srand(time(NULL));
    int maxInt = atoi(args[1]);
    int dataSetLength = atoi(args[2]);
    int searchSetLength = atoi(args[3]);

    int *dataSet = generateDataSet(maxInt, dataSetLength);
    bubblesort(dataSet, dataSetLength);
    int *searchSet = generateDataSet(maxInt, searchSetLength);

    int i;
    printf("Data Set:\n");
    for (i = 0; i < dataSetLength; i++)
    {
        printf("%d,", dataSet[i]);
    }
    printf("\nSearch Set:\n");
    for (i = 0; i < searchSetLength; i++)
    {
        printf("%d,", searchSet[i]);
    }
    printf("\n");

    int x = 0;
    int foundSet[searchSetLength];

    for (x = 0; x < searchSetLength; x++)
    {
        foundSet[x] = 0;
        //printf("%d, ", foundSet[x]);
    }

    for (i = 0; i < searchSetLength; i++)
    {
        int target = searchSet[i];
        foundSet[i] = binarySearch(dataSet, 0, dataSetLength, target);
    }

    printf("Found Set:\n");
    for (x = 0; x < searchSetLength; x++)
    {
        printf("%d, ", foundSet[x]);
    }
    printf("\n");
}