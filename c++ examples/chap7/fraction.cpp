#include <iostream>
#include <cmath>
#include <cassert>
#include "fraction.h"
using namespace std;

Fraction::Fraction(int num, int den = 1)
: numer(num), denom(den)
{
    normalize();
}

Fraction::Fraction()
: numer(0), denom(1)
{

}

Fraction::Fraction(const Fraction& fract)
: numer(fract.numer), denom(fract.denom)
{

}

Fraction::~Fraction()
{

}

int Fraction::getNumer() const
{
    return numer;
}

int Fraction::getDenom() const
{
    return denom;
}

void Fraction::print() const
{
    cout << numer << "/" << denom << endl;
}

void Fraction::setNumer(int num)
{
    numer = num;
    normalize();
}

void Fraction::setDenom(int den)
{
    denom = den;
    normalize();
}

void Fraction::normalize() //부호 변경과 약분(공약수가 없으면 1로)
{
    if(denom == 0)
    {
        cout << "잘못된 분모값입니다. 프로그램을 중단합니다." << endl;
        assert(false);
    }

    if(denom < 0)
    {
        denom = - denom;
        numer = - numer;
    }

    int divisor = gcd(abs(numer), abs(denom)); //절대값을 매개변수로 줌
    numer = numer / divisor;        //최대공약수로 나누기
    denom = denom / divisor;
}

int Fraction::gcd(int n, int m) //분자와 분모의 최대공약수 찾는 함수
{
    int gcd = 1;
    for(int k = 1; k <=n && k <= m; k++)
    {
        if(n % k == 0 && m % k == 0)
        {
            gcd = k;
        }
    }
    return gcd;
}