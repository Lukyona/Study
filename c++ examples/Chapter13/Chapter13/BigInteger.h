#pragma once
#include <iostream>
#include <string>
class BigInteger
{
private:
    std::string number;

public:
    BigInteger();
    BigInteger(int val);

    BigInteger operator + (const BigInteger& other);
    BigInteger operator - (const BigInteger& other);

    friend std::ostream& operator << (std::ostream& os, const BigInteger& bInt);
};

