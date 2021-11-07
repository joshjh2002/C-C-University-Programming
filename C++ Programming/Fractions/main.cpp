#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction myfraction1(1, 3);
    myfraction1.print<double>();

    Fraction myfraction2(1, 3);
    myfraction2.print<double>();

    std::cout << "\n";
    Fraction myfraction3 = myfraction1 + myfraction2;
    myfraction3.print<double>();

    myfraction3 = myfraction3.simplify();
    myfraction3.print<double>();

    Fraction myfraction4(6, 2);
    myfraction4 = myfraction4.simplify();
    myfraction4.print<double>();

    ++myfraction4;
    myfraction4.print<double>();
}