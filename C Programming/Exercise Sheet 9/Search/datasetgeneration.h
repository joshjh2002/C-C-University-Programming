#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *generateDataSet(int maxInt, int setSize);
void bubblesort(int *dataSet, int setSize);
void swap(int *xp, int *yp);
int binarySearch(int *dataSet, int lower, int higher, int target);