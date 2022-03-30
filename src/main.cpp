#include <iostream>
#include <stdio.h>
#include "include/ComplexNumber.h"

int main(int argc, char** argv) {

    ComplexNumber<float> c1(4.0, 2.0);
    ComplexNumber<float> c2(0.0, 13.0);
    ComplexNumber<float> c3(0.0, 1.0);

    ComplexNumber<float> z = (c1 + c2) * c3;
    printf("i*((4+2*i)+13*i) = \"%s\"\n", (char*) z);

    // sqrt(-1)
    printf("sqrt(-1) = \"%s\"\n", (char*) ComplexNumber<int>::Sqrt(-1));

    return 0;
}