#include "Complex.h"

Complex::Complex(double r, double i)
    :rPart(r), iPart(i)
{
}

Complex& Complex::operator+=(const Complex& other)
{
    rPart += other.rPart;
    iPart += other.iPart;
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    rPart -= other.rPart;
    iPart -= other.iPart;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    rPart = (rPart * other.rPart) - (iPart * other.iPart);
    iPart = (rPart * other.iPart) + (other.rPart + iPart);
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    rPart = (rPart * other.rPart) + (iPart * other.iPart);
    iPart = (( - 1 * (rPart * other.iPart)) + (other.rPart + iPart)) / (pow(other.rPart * 2, 2) + pow(other.iPart * 2, 2));
    return *this;
}

const Complex Complex::operator+(const Complex& other)
{
    double newR = rPart + other.rPart;
    double newI = iPart + other.iPart;
    return Complex(newR, newI);
}

const Complex Complex::operator-(const Complex& other)
{
    double newR = rPart - other.rPart;
    double newI = iPart - other.iPart;
    return Complex(newR, newI);
}

const Complex Complex::operator*(const Complex& other)
{
    double newR = (rPart * other.rPart) - (iPart * other.iPart);
    double newI = (rPart * other.iPart) + (other.rPart + iPart);
    return Complex(newR, newI);
}

const Complex Complex::operator/(const Complex& other)
{
    double newR = (rPart * other.rPart) + (iPart * other.iPart);
    double newI = ((-1 * (rPart * other.iPart)) + (other.rPart + iPart)) / (pow(other.rPart * 2, 2) + pow(other.iPart * 2, 2));
    return Complex(newR, newI);
}

std::ostream& operator<<(std::ostream& os, const Complex& comp)
{
    os << comp.rPart << " + " << comp.iPart << "i" << std::endl;
    return os;
}
