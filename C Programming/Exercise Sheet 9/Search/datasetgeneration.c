#include "datasetgeneration.h"

int *generateDataSet(int maxInt, int setSize)
{
    int *dataSet = malloc(sizeof(int) * setSize);

    int i;
    for (i = 0; i < setSize; i++)
    {
        dataSet[i] = rand() % maxInt;
    }

    return dataSet;
}

void bubblesort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int binarySearch(int *dataSet, int lower, int higher, int target)
{
    if (higher >= lower) { 
        int mid = lower + (higher - lower) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (dataSet[mid] == target) 
        {
            int counter = 1;
            int i;
            for (i = mid + 1; i < higher; i++)
            {
                if (dataSet[i] == target)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }

            for (i = mid - 1; i > lower; i--)
            {
                if (dataSet[i] == target)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            return counter;
        }
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (dataSet[mid] > target) 
            return binarySearch(dataSet, lower, mid - 1, target); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(dataSet, mid + 1, higher, target); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return 0;
}