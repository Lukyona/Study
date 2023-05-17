#include "Money.h"

Money::Money()
    :USD(0), cent(0)
{
}

Money::Money(int d, int c)
    :USD(d), cent(c)
{
}

Money Money::operator+(const Money& other)
{
    Money result;
    result.USD = USD + other.USD;
    result.cent = cent + other.cent;

    return result;
}

Money Money::operator-(const Money& other)
{
    Money result;
    result.USD = USD - other.USD;
    result.cent = cent - other.cent;

    return result;
}

Money& Money::operator*=(int num)
{
    USD *= num;
    cent *= num;

    if (cent >= 100)
    {
        USD = cent / 100;
        cent = cent % 100;
    }

    return *this;
}

Money& Money::operator/=(int num)
{
    USD /= num;
    cent /= num;

    return *this;
}

bool Money::operator<(const Money& other)
{
    if (USD > other.USD)
        return false;
    else if (USD < other.USD)
        return true;
    else
    {
        if (cent < other.cent)
            return true;
        else
            return false;
    }
}

bool Money::operator>(const Money& other)
{
    if (USD < other.USD)
        return false;
    else if (USD > other.USD)
        return true;
    else
    {
        if (cent > other.cent)
            return true;
        else
            return false;
    }
}

bool Money::operator==(const Money& other)
{
    if (USD == other.USD && cent == other.cent)
        return true;
    else
        return false;
}

bool Money::operator!=(const Money& other)
{
    return !(*this == other);
}
