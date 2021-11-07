#include <stdio.h>
#include <stdlib.h>

int f(int x);

int main(int argc, char *args[])
{
	for (int i = 0; i < 20; i++)
	{
		printf("%d   ", i);
	}
	printf("\n_____________________\n");
	int d = 10;
	while (d != 0)
	{
		printf("%d   ", d);
		d--;
	}
	printf("\n");
	
	
	return 0;
}

int f(int x)
{
	return 2 * x + 1;
}

//f(x) = 2x+1
//f(2) = 2(2)+1
//f(2) = 4+1
//f(2) = 5
