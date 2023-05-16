#pragma once
#include <iostream>
class Complex
{
private:
    double rPart;
    double iPart;
public:
    Complex(double r, double i);
    Complex& operator +=(const Complex& other);
    Complex& operator -=(const Complex& other);
    Complex& operator *=(const Complex& other);
    Complex& operator /=(const Complex& other);

    const Complex operator +(const Complex& other);
    const Complex operator -(const Complex& other);
    const Complex operator *(const Complex& other);
    const Complex operator /(const Complex& other);

    friend std::ostream& operator<< (std::ostream& os, const Complex& comp);
        
};

