#include "fraction.h"

Fraction& multiply(Fraction& fract1, Fraction& fract2, Fraction& result) // denom 분모
{
    result.setDenom(fract1.getDenom() * fract2.getDenom());
    result.setNumer(fract1.getNumer() * fract2.getNumer());

    return result;
    
}

int main()
{
    Fraction one(6, 10);
    Fraction two(7, 10);
    Fraction result;

    cout << "두 분수를 곱한 결과는 ";
    multiply(one, two, result).print();

    return 0;
}