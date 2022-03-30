#include "include/ComplexNumber.h"
#include <stdio.h>
#include <string>
#include <math.h> // for sqrt

int calcModulus(int real, int imaginary) {
    return sqrt(real*real + imaginary*imaginary);
}

int calcArgument(int real, int imaginary) {
    return atan(imaginary/real);
}

template<> ComplexNumber<int>::ComplexNumber(int realValue, int imaginaryValue) {
    real = realValue;
    imaginary = imaginaryValue;
}

template<> ComplexNumber<int>::ComplexNumber(int realValue) {
    real = realValue;
    imaginary = 0;
}

// euler
template<> int ComplexNumber<int>::GetModulus() {
    return modulus;
}

template<> int ComplexNumber<int>::GetArgument() {
    return argument;
}

template<> void ComplexNumber<int>::Print() {
    printf("%d + %di\n", real, imaginary);
}

// getters and setters
template<> int ComplexNumber<int>::GetReal() {
    return real;
}

template<> void ComplexNumber<int>::SetReal(int newReal) {
    real = newReal;

    // the modulus and argument could be different now that real has changed
    modulus = calcModulus(real, imaginary);
    argument = calcArgument(real, imaginary);
}

template<> int ComplexNumber<int>::GetImaginary() {
    return imaginary;
}

template<> void ComplexNumber<int>::SetImaginary(int newImaginary) {
    imaginary = newImaginary;

    // the modulus and argument could be different now that imaginary has changed
    modulus = calcModulus(real, imaginary);
    argument = calcArgument(real, imaginary);
}

// operator overloads
template<> ComplexNumber<int> ComplexNumber<int>::operator +(ComplexNumber<int> other) {
    const int otherReal = other.GetReal();
    const int otherImag = other.GetImaginary();

    ComplexNumber<int> cn = ComplexNumber<int>(real + otherReal, imaginary + otherImag);
    return cn;
}

template<> ComplexNumber<int> ComplexNumber<int>::operator -(ComplexNumber<int> other) {
    const int otherReal = other.GetReal();
    const int otherImag = other.GetImaginary();

    ComplexNumber<int> cn = ComplexNumber<int>(real - otherReal, imaginary - otherImag);
    return cn;
}

template<> ComplexNumber<int> ComplexNumber<int>::operator *(ComplexNumber<int> other) {
    const int a = real;
    const int b = imaginary;
    const int x = other.GetReal();
    const int y = other.GetImaginary();

    ComplexNumber<int> cn = ComplexNumber<int>(a*x - b*y, a*y + b*x);
    return cn;
}

template<> ComplexNumber<int> ComplexNumber<int>::operator /(ComplexNumber<int> other) {
    const int a = real;
    const int b = imaginary;
    const int x = other.GetReal();
    const int y = other.GetImaginary();

    ComplexNumber<int> cn = ComplexNumber<int>((a*x + b*y)/(x*x + y*y), (-a*y+b*x)/(x*x+y*y));
    return cn;
}

// for printing with cout
template<> ComplexNumber<int>::operator char*() const {

    // generate the string
    std::string realStr = std::to_string(real);
    std::string imagStr = std::to_string(imaginary);
    std::string str = realStr + " + " + imagStr + "i\0";

    // get the c string from the string
    const char* c_str = str.c_str();
    char* c_str_val = (char*) c_str; // cast to non const char*

    return c_str_val;
}

// static functions
template<> ComplexNumber<int> ComplexNumber<int>::Sqrt(int num) {
    ComplexNumber<int> root(0,0);

    if (num < 0) {
        root.SetImaginary(-num);
    } else {
        root.SetReal(sqrt(num));
    }

    return root;
}