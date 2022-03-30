#pragma once

template<class T>
class ComplexNumber {
private:
    T real, imaginary, modulus, argument;
public:
    ComplexNumber(T realValue, T imaginaryValue);
    ComplexNumber(T realValue);

    T GetModulus(); // absolute value or magnitude
    T GetArgument(); // the angle

    void Print();

    T GetReal();
    void SetReal(T newReal);
    T GetImaginary();
    void SetImaginary(T newImaginary);

    ComplexNumber operator +(ComplexNumber other);
    ComplexNumber operator -(ComplexNumber other);
    ComplexNumber operator *(ComplexNumber other);
    ComplexNumber operator /(ComplexNumber other);
    //ComplexNumber operator %(ComplexNumber other); // coming soon
    // for printing with cout
    //ComplexNumber operator <<(ComplexNumber after);  // coming soon
    operator char*() const;

    // static functions
    static ComplexNumber Sqrt(T num);
};