#include "BigInteger.h"

BigInteger::BigInteger()
    :number("0")
{
}

BigInteger::BigInteger(int val)
{
    number = std::to_string(val);
}

BigInteger BigInteger::operator+(const BigInteger& other)
{
    BigInteger result;
    result.number = std::to_string(std::stoi(number) + std::stoi(other.number));
    return result;
}

BigInteger BigInteger::operator-(const BigInteger& other)
{
    BigInteger result;
    result.number = std::to_string(std::stoi(number) - std::stoi(other.number));
    return result;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& bInt)
{
    os << bInt.number << std::endl;

    return os;
}


//int main()
//{
//    BigInteger one(7);
//    BigInteger two(8);
//
//    BigInteger three = one + two;
//
//    std::cout << three;
//
//    return 0;
//}