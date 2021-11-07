#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int decBin(int n,int size){
	int i, k;
	for (i = (size-1); i >= 0; i--)
	{
		k = n >> i;
		if (k & 1)
		printf("1");
		else
		printf("0");
	}
	return 0;
}


union FloatingPoint {
	struct {
		unsigned int sign : 1;
		unsigned int exponent : 8;
		unsigned int mantissa : 23;
	} raw;
	float f;
} number;

int main(int argc, char * argv[]) {
	float input = atof(argv[1]);
	number.f = input;
	int mant = number.raw.mantissa;
	int exp = number.raw.exponent;
	int sig = number.raw.sign;
	
	decBin(sig,1);
	printf("|");
	decBin(exp,8);
	printf("|");
	decBin(mant,23);
	printf("\n");
	return 0;
}
