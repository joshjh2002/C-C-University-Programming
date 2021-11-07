#include <stdio.h>
#include <math.h>

int main()
{

    int input1, input2, z = 0;

    printf("Please input the value 1: ");
    scanf("%d", &input1);

    printf("Please input the value 2: ");
    scanf("%d", &input2);

    //-------------------------------------
    int d;
    int a;
    for (d = input1; d <= input2; d++)
    {
        for (a = 1; a <= d; a++)
        {
            if (input1 % a == 0)
            {
                z++;
            }
        }
        printf("%d ", d);
    }

    return 0;
}