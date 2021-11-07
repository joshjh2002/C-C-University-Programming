#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double my_mean(double numbers[], int argc)
{
    double sum = 0;
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        sum += numbers[i];
    }

    int mean = sum / argc;

    return mean;
}

int my_max(double numbers[], int argc)
{
    double max = numbers[0];
    int i = 0;
    for (i = 1; i < argc; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    return 0;
}

double my_sd(double numbers[], int argc)
{
    double sd = 0;
    double mean = my_mean(numbers, argc);
    int i = 0;

    for (i = 0; i < argc; i++)
    {
        double sum = (numbers[i] - mean);
        sd += sum * sum;
    }

    sd = sd/argc;

    sd = pow(sd, 0.5);

    return sd;
}