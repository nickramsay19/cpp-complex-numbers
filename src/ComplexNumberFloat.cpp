#include "include/ComplexNumber.h"
#include <stdio.h>
#include <string>
#include <math.h> // for sqrt

float calcModulus(float real, float imaginary) {
    return sqrt(real*real + imaginary*imaginary);
}

float calcArgument(float real, float imaginary) {
    return atan(imaginary/real);
}

template<> ComplexNumber<float>::ComplexNumber(float realValue, float imaginaryValue) {
    real = realValue;
    imaginary = imaginaryValue;
}

template<> ComplexNumber<float>::ComplexNumber(float realValue) {
    real = realValue;
    imaginary = 0;
}

// euler
template<> float ComplexNumber<float>::GetModulus() {
    return modulus;
}

template<> float ComplexNumber<float>::GetArgument() {
    return argument;
}

template<> void ComplexNumber<float>::Print() {
    prfloatf("%d + %di\n", real, imaginary);
}

// getters and setters
template<> float ComplexNumber<float>::GetReal() {
    return real;
}

template<> void ComplexNumber<float>::SetReal(float newReal) {
    real = newReal;

    // the modulus and argument could be different now that real has changed
    modulus = calcModulus(real, imaginary);
    argument = calcArgument(real, imaginary);
}

template<> float ComplexNumber<float>::GetImaginary() {
    return imaginary;
}

template<> void ComplexNumber<float>::SetImaginary(float newImaginary) {
    imaginary = newImaginary;

    // the modulus and argument could be different now that imaginary has changed
    modulus = calcModulus(real, imaginary);
    argument = calcArgument(real, imaginary);
}

// operator overloads
template<> ComplexNumber<float> ComplexNumber<float>::operator +(ComplexNumber<float> other) {
    const float otherReal = other.GetReal();
    const float otherImag = other.GetImaginary();

    ComplexNumber<float> cn = ComplexNumber<float>(real + otherReal, imaginary + otherImag);
    return cn;
}

template<> ComplexNumber<float> ComplexNumber<float>::operator -(ComplexNumber<float> other) {
    const float otherReal = other.GetReal();
    const float otherImag = other.GetImaginary();

    ComplexNumber<float> cn = ComplexNumber<float>(real - otherReal, imaginary - otherImag);
    return cn;
}

template<> ComplexNumber<float> ComplexNumber<float>::operator *(ComplexNumber<float> other) {
    const float a = real;
    const float b = imaginary;
    const float x = other.GetReal();
    const float y = other.GetImaginary();

    ComplexNumber<float> cn = ComplexNumber<float>(a*x - b*y, a*y + b*x);
    return cn;
}

template<> ComplexNumber<float> ComplexNumber<float>::operator /(ComplexNumber<float> other) {
    const float a = real;
    const float b = imaginary;
    const float x = other.GetReal();
    const float y = other.GetImaginary();

    ComplexNumber<float> cn = ComplexNumber<float>((a*x + b*y)/(x*x + y*y), (-a*y+b*x)/(x*x+y*y));
    return cn;
}

// for prfloating with cout
template<> ComplexNumber<float>::operator char*() const {

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
template<> ComplexNumber<float> ComplexNumber<float>::Sqrt(float num) {
    ComplexNumber<float> root(0,0);

    if (num < 0) {
        root.SetImaginary(-num);
    } else {
        root.SetReal(sqrt(num));
    }

    return root;
}