#include <iostream>
#include "templateClass.h"
#include "operation_overloading.h"
using namespace std;

int main()
{
	Overloading o1(1, 2);
	Overloading o2(2, 1);

	Overloading o3 = o1 + o2;

	o3.print();
}